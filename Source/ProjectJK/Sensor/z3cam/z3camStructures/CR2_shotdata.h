// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CR2_shotdata.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_shotdata
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 ballspeedX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 clubspeed_BX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 clubspeed_AX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 clubpathX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 clubfaceangleX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 backspin;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 sidespin;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 azimuthX10;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdata)	int32 inclineX10;
};
