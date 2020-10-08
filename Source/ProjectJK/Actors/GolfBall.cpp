// Fill out your copyright notice in the Description page of Project Settings.


#include "GolfBall.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AGolfBall::AGolfBall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGolfBall::BeginPlay()
{
	Super::BeginPlay();
	
	BindComponent();
	
	MySphereMesh->OnComponentHit.Clear();
	MySphereMesh->OnComponentHit.AddDynamic(this, &AGolfBall::OnHit);

}

// Called every frame
// void AGolfBall::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// }

// Called to bind functionality to input
void AGolfBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGolfBall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	isGround = true;
	FString name = UKismetSystemLibrary::GetDisplayName((UObject*)Hit.PhysMaterial.Get());
	UKismetSystemLibrary::PrintString(GetWorld(), name, true, false, FLinearColor::Green, 0.5f);
	if(name.Contains("water"))
		UE_LOG(LogTemp, Log, TEXT("asdfSSADFASDF ------ water"))
}

void AGolfBall::BindComponent()
{
	MySphereMesh = FindComponentByClass<UStaticMeshComponent>();
	MySpringArm = FindComponentByClass<USpringArmComponent>();
	MyCamera = FindComponentByClass<UCameraComponent>();
}

void AGolfBall::MoveForward(float AxisValue)
{
	if (MySphereMesh)
		MySphereMesh->AddTorqueInRadians(UKismetMathLibrary::MakeVector(RollTorque * AxisValue, 0.f, 0.f));
}

void AGolfBall::TurnRight(float AxisValue)
{
	if (MySphereMesh)
		MySphereMesh->AddTorqueInRadians(UKismetMathLibrary::MakeVector(0.f, RollTorque * AxisValue, 0.f));
}

void AGolfBall::Jump()
{
	if (isGround)
	{
		MySphereMesh->AddImpulse(FVector(0.f, 0.f, 500000));
		isGround = false;
	}
}

void AGolfBall::CameraZoomIn()
{
	if (MySpringArm)
		MySpringArm->TargetArmLength -= 100.f;
}

void AGolfBall::CameraZoomOut()
{
	if (MySpringArm)
		MySpringArm->TargetArmLength += 100.f;
}
