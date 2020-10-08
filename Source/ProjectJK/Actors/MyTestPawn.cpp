// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPawn.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyTestPawn::AMyTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RollTorque = 1000.f;
	
	MyPawnMovementComponent = CreateDefaultSubobject<UTestPawnMovementComponent>(TEXT("CustomMovementComponent"));
	MyPawnMovementComponent->UpdatedComponent = RootComponent;


	///it's test code for instantiate in constructor( CreateDefaultSubobject and FObjectFinder can only use in constructors )
// 	MyParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TraceParticles"));
// 	MyParticle->SetupAttachment(GetRootComponent());
// 	MyParticle->bAutoActivate = false;
// 	MyParticle->SetRelativeLocation(FVector(-20.f, 0.0f, 20.f));
// 	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/Tropical_Jungle_Pack/Particles/P_Steam_Lit_MOD.P_Steam_Lit_MOD"));
// 	if (ParticleAsset.Succeeded())
// 		MyParticle->SetTemplate(ParticleAsset.Object);
	///
}

// Called when the game starts or when spawned
void AMyTestPawn::BeginPlay()
{
	Super::BeginPlay();

	BindComponent();
}

// Called every frame
void AMyTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
		MyPawnMovementComponent->AddInputVector(GetActorUpVector() * -1.f);
}

// Called to bind functionality to input
void AMyTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("ParticleToggle", IE_Pressed, this, &AMyTestPawn::ParticleToggle);
	PlayerInputComponent->BindAction("CameraZoomIn", IE_Pressed, this, &AMyTestPawn::CameraZoomIn);
	PlayerInputComponent->BindAction("CameraZoomOut", IE_Pressed, this, &AMyTestPawn::CameraZoomOut);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyTestPawn::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyTestPawn::MoveForward);
	PlayerInputComponent->BindAxis("TurnRight", this, &AMyTestPawn::TurnRight);

}

UPawnMovementComponent* AMyTestPawn::GetMovementComponent() const
{
	return MyPawnMovementComponent;
}

void AMyTestPawn::ReceivePossessed(AController* NewController)
{
	UE_LOG(LogTemp, Log, TEXT("i'm possessed"));
	isPossessed = true;
}

void AMyTestPawn::ReceiveUnpossessed(AController* OldController)
{
	UE_LOG(LogTemp, Log, TEXT("i'm Unpossessed"));
	isPossessed = false;
}

void AMyTestPawn::BindComponent()
{
	//for test
	MySphereMesh = FindComponentByClass<UStaticMeshComponent>();
	MySpringArm = FindComponentByClass<USpringArmComponent>();
	MyCamera = FindComponentByClass<UCameraComponent>();
	MyParticle = FindComponentByClass<UParticleSystemComponent>();

	///test code for runtime instantiate
// 	MyParticle = NewObject<UParticleSystemComponent>(MySphereMesh, UParticleSystemComponent::StaticClass(), TEXT("TraceParticles"));
// 	UParticleSystem* ParticleAsset = Cast<UParticleSystem>(StaticLoadObject(UParticleSystem::StaticClass(), MyParticle, TEXT("/Game/Tropical_Jungle_Pack/Particles/P_Steam_Lit_MOD.P_Steam_Lit_MOD")));
// 	MyParticle->SetTemplate(ParticleAsset);
	///

}

void AMyTestPawn::MoveForward(float AxisValue)
{
	if (MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
		MyPawnMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);

// 	if (MySphereMesh && AxisValue > 0.f)
// 		MySphereMesh->AddTorqueInRadians(UKismetMathLibrary::MakeVector(RollTorque * AxisValue, 0.f, 0.f));
}

void AMyTestPawn::TurnRight(float AxisValue)
{
	if (MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += AxisValue;
		SetActorRotation(NewRotation);
	}
	//MyPawnMovementComponent->AddInputVector(GetActorRightVector() * AxisValue);

// 	if (MySphereMesh && AxisValue > 0.f)
// 		MySphereMesh->AddTorqueInRadians(UKismetMathLibrary::MakeVector(0.f, RollTorque * AxisValue, 0.f));
}

void AMyTestPawn::Jump()
{
	if (MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
	{
		MyPawnMovementComponent->AddInputVector(GetActorUpVector());
		UE_LOG(LogTemp, Log, TEXT("Jump"));
	}
}

void AMyTestPawn::CameraZoomIn()
{
	if (MySpringArm)
		MySpringArm->TargetArmLength -= 100.f;
}

void AMyTestPawn::CameraZoomOut()
{
	if (MySpringArm)
		MySpringArm->TargetArmLength += 100.f;
}

void AMyTestPawn::ParticleToggle()
{
	if (MyParticle && MyParticle->Template)
		MyParticle->ToggleVisibility();
}
