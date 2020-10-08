// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TestPawnMovementComponent.h"
#include "GolfBall.generated.h"

UCLASS()
class PROJECTJK_API AGolfBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGolfBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void BindComponent();

	void MoveForward(float AxisValue);
	void TurnRight(float AxisValue);
	void Jump();
	void CameraZoomIn();
	void CameraZoomOut();

public:
	UPROPERTY()
	UStaticMeshComponent* MySphereMesh = nullptr;
	UPROPERTY()
	USpringArmComponent* MySpringArm = nullptr;
	UPROPERTY()
	UCameraComponent* MyCamera = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GolfBall)
	float RollTorque = 0.f;
	UPROPERTY()
	bool isGround;
};
