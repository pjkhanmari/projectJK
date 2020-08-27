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

	void InitSensor();
	void StartSensor();
	void RestartSensor();
	void StopSensor();
	void ShutdownSensor();
	ESensorState CheckSensorState();
	void SetProperty();

public:
	UPROPERTY()
	int32 CurrentClub;
	UPROPERTY()
	int32 CurrentHand;
	

private:
	UPROPERTY() 
	class Uz3camHandler* handler = nullptr;
	UPROPERTY() 
	bool isSensorConnected = false;
	
};
