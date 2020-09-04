// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SensorManager.generated.h"

/**
 * 
 */

UENUM()
enum class ESensorState : uint8
{
	E_NULL,
	E_READY,
	E_GOODSHOT,
	E_TRIALSHOT,
	E_DISCONNECT,
	E_BIGSHADOW,
	E_NOBALL,
	E_LOWACTIVE,
	E_STATUSERR
};

UCLASS()
class PROJECTJK_API USensorManager : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();

	FString InitSensor();
	FString StartSensor();
	FString RestartSensor();
	FString StopSensor();
	FString ShutdownSensor();
	ESensorState CheckSensorState();
	FString GetVersion();
	void SetProperty();
	FString StartProcess();
	bool IsSensorConnected();
//	void StartSensorCheck();

public:
	UPROPERTY()
	int32 club;
	UPROPERTY()
	int32 hand;
	UPROPERTY()
	int32 altitude;
	UPROPERTY()
	int32 markingOption;
	UPROPERTY()
	float windMag;
	UPROPERTY()
	float windDir;
	UPROPERTY()
	int32 calculateClubOption;

public:
	UPROPERTY() 
	class Uz3camHandler* handler = nullptr;
	UPROPERTY() 
	bool isSensorConnected = false;
	
};
