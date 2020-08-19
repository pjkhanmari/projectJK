// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CR2_guid.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_guid
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY() int32  Data1;
	UPROPERTY() int16 Data2;
	UPROPERTY() int16 Data3;
	UPROPERTY() int8  Data4[8];
};
