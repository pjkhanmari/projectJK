// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilFunctionLibSensor.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUtilFunctionLibSensor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


private:
	UPROPERTY()
	UStaticMesh* sm_cylinder;
	
};
