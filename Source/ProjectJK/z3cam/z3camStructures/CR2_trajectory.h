// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#define CR2TRAJECTORYMAXCOUNT	1000
/**
 * 
 */

USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_trajectory
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = cr2_trajectory) int32 count;
	UPROPERTY() FCR2_point pts[CR2TRAJECTORYMAXCOUNT]; // Unit of x, y, z: [cm],   t: [0.001sec == msec]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = cr2_trajectory) int32 peakheight;                         // [m]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = cr2_trajectory) int32 carrydistance;                      // [m]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = cr2_trajectory) int32 sidedistance;                       // [m]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = cr2_trajectory) int32 flighttimeX1000;                    // [msec]
};
