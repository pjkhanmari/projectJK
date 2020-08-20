// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "z3camSDK.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API Uz3camSDK : public UObject
{
	GENERATED_BODY()
public:
	Uz3camSDK();
	~Uz3camSDK();

public:
	static bool importDLL(FString folder, FString name);
	static void freeDLL();

	static bool import_initMethod();
#if defined(_WIN64)
	static void* CR2_init(uint32 sensorcode, uint32 sensornum, int64 p0, int64 p1, int64 p2, int64 p3);
#else
	static void* CR2_init(uint32 sensorcode, uint32 sensornum, int32 p0, int32 p1, int32 p2, int32 p3);
#endif

	static bool import_deleteMethod();
	static int CR2_delete(void* hand);

	static bool import_commandMethod();
#if defined(_WIN64)
	static int CR2_command(void* h, uint32 cmd, int64 p0, int64 p1, int64 p2, int64 p3);
#else
	static int CR2_command(void* h, uint32 cmd, int32 p0, int32 p1, int32 p2, int32 p3);
#endif
};
