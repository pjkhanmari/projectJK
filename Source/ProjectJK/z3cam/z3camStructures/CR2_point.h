// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CR2_point.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_point
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_point) int32 x;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_point) int32 y;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_point) int32 z;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_point) int32 t;
};
