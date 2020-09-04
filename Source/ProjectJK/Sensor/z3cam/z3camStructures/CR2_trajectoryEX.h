// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_point.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_vs.h"
#include "CR2_trajectoryEX.generated.h"

/**
 * 
 */

#define CR2TRAJECTORYMAXCOUNT	1000

USTRUCT()
struct PROJECTJK_API FCR2_trajectoryEX
{
	GENERATED_USTRUCT_BODY()
	
public:
	int32 count;
	FCR2_point pts_mm[CR2TRAJECTORYMAXCOUNT];	// Unit of x, y, z: [mm],   t: [0.001sec == msec]
	int32 peakheight;								// [m]
	int32 carrydistance;							// [m]
	int32 sidedistance;							// [m]
	int32 flighttimeX1000;						// [msec]
	FCR2_vs vs[CR2TRAJECTORYMAXCOUNT];	// Unit of vx, vy, vz: [mm/s]
										//       sidespin, backspin: [rpm]
										//       t: [0.001sec == msec]
	int udata[32];								// Reserved.
};
