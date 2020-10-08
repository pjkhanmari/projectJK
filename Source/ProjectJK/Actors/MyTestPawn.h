// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Camera/CameraComponent.h"
#include "TestPawnMovementComponent.h"
#include "MyTestPawn.generated.h"

class USpringArmComponent;
class UTestPawnMovementComponent;
namespace ForwardDeclare { class UStaticMeshComponent; }
namespace ForwardDeclare { class UParticleSystemComponent; }
namespace ForwardDeclare { class UCameraComponent; }

UCLASS()
class PROJECTJK_API AMyTestPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTestPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPawnMovementComponent* GetMovementComponent() const override;

	void ReceivePossessed(AController* NewController);
	void ReceiveUnpossessed(AController* OldController);
public:
	void BindComponent();

	void MoveForward(float AxisValue);
	void TurnRight(float AxisValue);
	void Jump();
	void CameraZoomIn();
	void CameraZoomOut();
	void ParticleToggle();
	
public:
	UPROPERTY()
	UStaticMeshComponent* MySphereMesh = nullptr;
	UPROPERTY()
	UParticleSystemComponent* MyParticle = nullptr;
	UPROPERTY()
	USpringArmComponent* MySpringArm = nullptr;
	UPROPERTY()
	UCameraComponent* MyCamera = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TestPawnVariable)
	UTestPawnMovementComponent* MyPawnMovementComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TestPawnVariable)
	float RollTorque = 0.f;
	UPROPERTY()
	bool isPossessed = false;
};
