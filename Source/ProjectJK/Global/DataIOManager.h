// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_shotdataEX.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_trajectoryEX.h"
#include "DataIOManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UDataIOManager : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize();

	FORCEINLINE void SetShotData(FCR2_shotdataEX data) { CurrShotData = data; }
	FORCEINLINE FCR2_shotdataEX GetShotData() { return CurrShotData; }
	FORCEINLINE void SetTrajectoryData(FCR2_trajectoryEX data) { CurrTrajectoryData = data; }
	FORCEINLINE FCR2_trajectoryEX GetTrajectoryData() { return CurrTrajectoryData; }
	
private:
	UPROPERTY()
	FCR2_shotdataEX CurrShotData;
	UPROPERTY()
	FCR2_trajectoryEX CurrTrajectoryData;
	
};
