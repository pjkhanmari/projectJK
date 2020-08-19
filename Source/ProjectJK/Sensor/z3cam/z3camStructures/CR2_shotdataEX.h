// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_guid.h"
#include "CR2_shotdataEX.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct PROJECTJK_API FCR2_shotdataEX
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) FCR2_guid shotguid;				// GUID of shot
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 category;					// Sensor category
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 rightlefthanded;			// 0: right-haned, 1: left-handed
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 xposx1000;					// Shot ball x position [mm]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 yposx1000;					// Shot ball y position [mm]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 zposx1000;					// Shot ball z position [mm]
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 ballspeedx1000;				// ball speed. [m/s] * 1000 = [mm/s]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 inclineX1000;				// ball incline. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 azimuthX1000;				// ball azimuth. [degree] * 1000
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 spincalc_method;			// Spin calc. method.  0: Using Ball/Club path. 1: Ball Marking based. 2: Dimple based.
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_spin;				// Spin calcuration assurance. 0-100
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 backspinX1000;				// backspin. [rpm] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 sidespinX1000;				// sidespin. [rpm] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 rollspinX1000;				// rollspin. [rpm] * 1000
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 clubcalc_method;			// club calc. method.  0: marking-less method, 1: another marking-less method, 2: bar-marking, 3: bar-marking and dot-marking
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_clubspeed;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_clubpath;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_faceangle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_attackangle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_loftangle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_lieangle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_faceimpactLateral;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 assurance_faceimpactVertical;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 clubspeedX1000;				// club speed. [m/s] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 clubpathX1000;				// club path angle. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 faceangleX1000;				// face angle. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 attackangleX1000;			// attack angle. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 loftangleX1000;				// loftangle. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 lieangleX1000;				// lie angle. [degree] * 1000
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 faceimpactLateralX1000;		// horizontal deviation of impact point from club center. [mm]
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = cr2_shotdataEX) int32 faceimpactVerticalX1000;	// vertical deviation of impact point from club center. [mm]
	
	UPROPERTY() int32 data[30];					// padding data. 

};