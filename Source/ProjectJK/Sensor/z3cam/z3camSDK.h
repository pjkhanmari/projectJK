// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PROJECTJK_API z3camSDK
{
public:
	z3camSDK();
	~z3camSDK();

public:
	static bool importDLL(FString folder, FString name);
	static void freeDLL();

	static bool import_initMethod();
	static void* CR2_init(int sensorcode, int sensornum, long long &p0, long long &p1, long long &p2, long long &p3);

	static bool import_deleteMethod();
	static int CR2_delete(void* hand);

	static bool import_commandMethod();
	static int CR2_command(void* h, unsigned int cmd, int p0, int p1, int p2, int p3);
};
