// Fill out your copyright notice in the Description page of Project Settings.


#include "LandCheckActor.h"
#include <../Private/KismetTraceUtils.h>
#include "Kismet/KismetSystemLibrary.h"
#include <PhysicalMaterials/PhysicalMaterial.h>
#include <PhysicsEngine/PhysicsSettings.h>
#include <Logging/LogMacros.h>


// Sets default values
ALandCheckActor::ALandCheckActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	m_nSurfaceType = 0;
	m_strSurfaceName = FName("Default");
	m_nLandCheckType = LAND_CHECK_TYPE::OBJECT;
	m_fSphereRadius = 42.1f; //  기본 골프공 반지름 2.1cm

	m_isDebug = false;
}



ALandCheckActor::~ALandCheckActor()
{

}

// Called when the game starts or when spawned
void ALandCheckActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
// void ALandCheckActor::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// 
// 	onLandCheck();
// }


void ALandCheckActor::onLandCheck()
{
	if (m_nLandCheckType == LAND_CHECK_TYPE::SPHERE)
	{
		//onLandSphereCheck();
	}
	else if(m_nLandCheckType == LAND_CHECK_TYPE::LINE)
	{
		onLandLineCheck();
	}
	else if (m_nLandCheckType == LAND_CHECK_TYPE::OBJECT)
	{
		onLandObjectCheck();
	}
}

void ALandCheckActor::onLandLineCheck()
{
	static int32 nCount = 0;

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("==== Plugin Call onTestFunction ===== %d"), nCount++));

	//FVector vLocation = GetActorLocation();
	FVector vStart = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();//GetActorLocation();

	FVector vForwardVector = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
	FVector vEnd = ((vForwardVector * 1000.0f) + vStart);

	if (m_isDebug)
	{
		DrawDebugLine(GetWorld(), vStart, vEnd, FColor::Green, false, 1, 0, 1);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("==== Plugin Actor Location ===== %s"), *vStart.ToString()));
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("==== Plugin Actor Forward ===== %s"), *vForwardVector.ToString()));
	}
}

void ALandCheckActor::onLandObjectCheck()
{
	
	results.Reset();
	
	FVector StartLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();//GetActorLocation();
	FVector EndLocation = StartLocation;// + GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector() * 400.0f;

	FCollisionShape ColShape = FCollisionShape::MakeSphere(m_fSphereRadius);
	
	bool IsHitResult = GetWorld()->SweepMultiByChannel(
		results,
		StartLocation,
		EndLocation, 
		FQuat::Identity,
		ECollisionChannel::ECC_WorldStatic,
		ColShape);

	if (IsHitResult)
	{
		for (auto& Hit : results)
			m_nSurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

		if(m_isDebug)
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("==== Plugin Actor Collision True")));
	}
	else
	{
		if(m_isDebug)
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("==== Plugin Actor Collision False")));
	}
}

void ALandCheckActor::onLandSphereCheck(FVector StartLocation, FVector EndLocation, FCollisionQueryParams Params, TArray<int32>& surfaceTypes)
{
	//FHitResult HitResult;
	results.Reset();

	//FVector StartLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();//GetActorLocation();
	//FVector EndLocation = StartLocation + FVector(0.f, 0.f, -50.f);// + GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector() * 400.0f;
	//FCollisionQueryParams Params;//Params(NAME_None, false, this);
// 	bool IsHitResult = GetWorld()->LineTraceMultiByChannel(
// 		results,
// 		StartLocation,
// 		EndLocation,
// 		ECollisionChannel::ECC_Visibility,
// 		Params
// 		);

	bool IsHitResult = GetWorld()->SweepMultiByChannel(
		results,
		StartLocation,
		EndLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_Visibility,
 		FCollisionShape::MakeSphere(m_fSphereRadius),
		Params);

	if (m_isDebug)
	{
		FColor DrawColor = IsHitResult ? FColor::Green : FColor::Red;
		DrawDebugSphere(GetWorld(), StartLocation, m_fSphereRadius, 10, DrawColor, false, -1.0f);
	}

	if (IsHitResult)
	{
		for (auto& Hit : results)
		{
			m_nSurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
			surfaceTypes.Emplace(m_nSurfaceType);

			if (m_nSurfaceType > 0)
			{
				FPhysicalSurfaceName phySurface = UPhysicsSettings::Get()->PhysicalSurfaces[m_nSurfaceType-1];
				m_strSurfaceName = phySurface.Name;
			}
			else
				m_strSurfaceName = FName("Default");

			if (m_isDebug)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("Physics SurfaceType : %d"), m_nSurfaceType));
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("Physics SurfaceType Name : %s"), *m_strSurfaceName.ToString()));
			}
		}
	}
	else
	{
		if (m_isDebug)
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("==== Plugin Actor Collision False")));
	}
}


