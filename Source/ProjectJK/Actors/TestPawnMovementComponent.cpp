// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawnMovementComponent.h"
#include "PhysicsEngine/PhysicsSettings.h"

UTestPawnMovementComponent::UTestPawnMovementComponent()
{
	Coefficient = 500.f;
}

UTestPawnMovementComponent::~UTestPawnMovementComponent()
{

}

void UTestPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
		return;

	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * Coefficient;
	//DesiredMovementThisFrame += FVector(FVector2D(), -0.1f /** UPhysicsSettings::Get()->DefaultGravityZ*/);
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		if (Hit.IsValidBlockingHit())
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
	}
}
