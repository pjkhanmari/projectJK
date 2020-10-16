// Fill out your copyright notice in the Description page of Project Settings.


#include "CarryTrajectory.h"
#include "ProjectJK.h"
#include "Sensor/z3cam/z3camStructures/CR2_point.h"
#include "Kismet/GameplayStatics.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACarryTrajectory::ACarryTrajectory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ACarryTrajectory::BeginPlay()
{
	Super::BeginPlay();
	
	instance = GAMEINSTANCE(this);
	instance->DelegateCollection->NewTrajectoryDataSet.AddDynamic(this, &ACarryTrajectory::DrawCarryTrajectory);
	LandChecker = (ALandCheckActor*)GetWorld()->SpawnActor(ALandCheckActor::StaticClass());
}

void ACarryTrajectory::EndPlay(EEndPlayReason::Type reason)
{
	instance->DelegateCollection->NewTrajectoryDataSet.RemoveDynamic(this, &ACarryTrajectory::DrawCarryTrajectory);
	Super::EndPlay(reason);
}

void ACarryTrajectory::SetLocations(FCR2_trajectoryEX trj, FVector StartLocation)
{
	Locations.Reset();

	for (FCR2_point point : trj.pts_mm)
	{
		if (point.x > SMALL_NUMBER || point.y > SMALL_NUMBER || point.z > SMALL_NUMBER)
			Locations.Emplace(FVector(point.x / 10.f, point.y / 10.f, point.z / 10.f) + StartLocation);
	}
}

void ACarryTrajectory::DrawCarryTrajectory()
{
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector StartLocation = pc->GetPawn()->GetActorLocation();
	FCR2_trajectoryEX trj = instance->DataIOManager->GetTrajectoryData();
	SetLocations(trj, StartLocation);

	FCollisionQueryParams Params;
	Params.bReturnPhysicalMaterial = true;
	TArray<int32> SurfaceTypes;
	SurfaceTypes.Reset();

	InitMeshVisibility();

	FVector LastLocation;

	for (int32 i = 1; i < Locations.Num(); i++)
	{
		if (trajecMeshes[i] == nullptr) continue;

		DeltaP = Locations[i] - Locations[i - 1];
		if (i > 1)
		{
			LandChecker->onLandSphereCheck(Locations[i - 1], Locations[i], Params, SurfaceTypes);
			if (SurfaceTypes.Num() > 0)
			{
				LastLocation = Locations[i];
				break;
			}
		}
		URealisticProjectileComponent::ScaleVisualEffect(trajecMeshes[i], Locations[i], DeltaP, StartLocation, 6.f);
		UE_LOG(LogTrajectory, Log, TEXT("[%d] Carry Trajectory Vector : %s"), i, *(Locations[i].ToString()));
#if WITH_EDITOR
		DrawDebugLine(GetWorld(), Locations[i - 1], Locations[i], FColor(255, 0, 0), true, -1.f, (uint8)'\000', 6.f);
#else
		trajecMeshes[i]->SetVisibility(true);
#endif
		LastLocation = Locations[i];
	}
	DrawRunTrajectory(LastLocation, FRotator());
}

void ACarryTrajectory::DrawRunTrajectory(FVector LastLocation, FRotator LastRotation)
{
	FVector Dummy;
	Locations.Reset();
	AActor* Instance;
	URealisticProjectileComponent* SpawnedComponent;
	UWorld* World;
	SetupTrajectoryComponent(LastLocation, LastRotation);

	FVector Dummy;
	InternalPredictTrajectory(World, WorldLocations, Rotations, Velocities, Dummy, Instance, SpawnedComponent, StartLocation, StartRotation, TimeToSimulate, StepTime, MaxPoints, false);
	for (int32 i = 1; i < Locations.Num(); i++) {
		UE_LOG(LogTrajectory, Log, TEXT("[%d] Run Trajectory Vector : %s"), i, *(Locations[i].ToString()));
		DrawDebugLine(GetWorld(), Locations[i - 1], Locations[i], FColor(255, 0, 0), true, -1.f, (uint8)'\000', 6.f);
	}
}

void ACarryTrajectory::InitMeshVisibility()
{
	for (auto mesh : trajecMeshes)
		mesh->SetVisibility(false);
}

void ACarryTrajectory::SetupTrajectoryComponent(FVector StartLocation, FRotator StartRotation)
{
	auto world = GetWorld();
	if (!world)
		return;
	UClass* ActorType = GolfBallActor.Get();
	if (!ActorType)
		return;
	FTransform SpawnTransform = FTransform(StartRotation, StartLocation, FVector(1.f, 1.f, 1.f));

	FActorSpawnParameters ASP;
	ASP.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ASP.bNoFail = true;
	auto OutActor = world->SpawnActor<AActor>(ActorType, SpawnTransform, ASP);

	if (!IsValid(OutActor))
		return;

	URealisticProjectileComponent* SpawnedComponent = OutActor->FindComponentByClass<URealisticProjectileComponent>();
	if (!SpawnedComponent)
	{
		OutActor->Destroy();
		return;
	}
	return;
}

// Called every frame
// void ACarryTrajectory::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// 
// }

