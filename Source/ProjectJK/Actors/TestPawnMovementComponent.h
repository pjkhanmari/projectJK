// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "TestPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UTestPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	UTestPawnMovementComponent();
	~UTestPawnMovementComponent();
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MovementComponentVar)
	float Coefficient = 0.f;
};
