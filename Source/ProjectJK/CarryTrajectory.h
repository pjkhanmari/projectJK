// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sensor/z3cam/z3camStructures/CR2_trajectoryEX.h"
#include "Actors/LandCheckActor.h"
#include "JKGameInstance.h"
#include "Actors/GolfBall.h"
#include "CarryTrajectory.generated.h"

class ALandCheckActor;
class UJKGameInstance;
class AGolfBall;

UCLASS()
class PROJECTJK_API ACarryTrajectory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACarryTrajectory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type reason) override;

public:
	UFUNCTION()
	void SetLocations(FCR2_trajectoryEX trj, FVector StartLocation);
	UFUNCTION()
	void DrawCarryTrajectory();
	UFUNCTION()
	void DrawRunTrajectory(FVector LastLocation, FRotator LastRotation);
	UFUNCTION()
	void InitMeshVisibility();

	void SetupTrajectoryComponent(FVector StartLocation, FRotator StartRotation);
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CarryTrajectory)
	TArray<UStaticMeshComponent*> trajecMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CarryTrajectory)
	TSubclassOf<AGolfBall> GolfBallActor;
	UPROPERTY()
	TArray<FVector> Locations;
	UPROPERTY()
	FVector DeltaP;

private:
	UPROPERTY()
	UJKGameInstance* instance;
	UPROPERTY()
	ALandCheckActor* LandChecker;
};
