// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CR2_vs.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_vs
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 vx;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 vy;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 vz;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 sidespin;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 backspin;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_vs) int32 t;
};
