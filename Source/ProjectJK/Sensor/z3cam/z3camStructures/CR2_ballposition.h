// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CR2_ballposition.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_ballposition
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_ballposition) int32 ballexist;          // 0: Don't Exist, 1: Exist
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_ballposition) int32 shotresult;         // 0: Last shot was NOT me.  1: Last shot was me!!
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_ballposition) int32 x;                  // X position [mm]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_ballposition) int32 y;                  // Y position [mm]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_ballposition) int32 z;                  // Z position [mm]
};
