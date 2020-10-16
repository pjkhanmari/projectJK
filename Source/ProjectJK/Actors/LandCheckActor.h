// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "LandCheckActor.generated.h"

enum LAND_CHECK_TYPE
{
	SPHERE = 0,
	LINE,
	OBJECT,
};

UCLASS(Config = Engine)
class PROJECTJK_API ALandCheckActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandCheckActor();
	~ALandCheckActor();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

public:	
	// Called every frame
	//void Tick(float DeltaTime) override;
public:

	FORCEINLINE void SetSphereRadius(float fRadius) { m_fSphereRadius = fRadius; }
	FORCEINLINE void SetLandCheckType(int32 nLandCheckType = LAND_CHECK_TYPE::SPHERE) { m_nLandCheckType = nLandCheckType; }

	FORCEINLINE int32 GetSurfaceType()		const { return m_nSurfaceType; }
	FORCEINLINE FName GetSufaceTypeName()	const { return m_strSurfaceName; }
	void onLandSphereCheck(FVector StartLocation, FVector EndLocation, FCollisionQueryParams Params, TArray<int32>& surfaceTypes);


protected:
	void onLandCheck();

	void onLandLineCheck();
	void onLandObjectCheck();

protected:
	UPROPERTY()
	int32 m_nSurfaceType;			// Physics Material Surface Type Index
	UPROPERTY()
	FName m_strSurfaceName;			// Physics Material Surface Type Name
	UPROPERTY()
	float m_fSphereRadius;			// Sphere Trace Radius

public:
	UPROPERTY()
	int32 m_nLandCheckType;			// LandCheckType Index
	UPROPERTY()
	bool  m_isDebug;
	UPROPERTY()
	TArray<FHitResult> results;
};
