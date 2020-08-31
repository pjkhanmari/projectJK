// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProjectJK/JKGameInstance.h"

extern PROJECTJK_API class UJKGameInstance* Instance;

#if WITH_EDITOR
#define GAMEINSTANCE(p) (UJKGameInstance::GetJKGameInstance(p))
#else
#define GAMEINSTANCE(p) Instance
#endif

//Sensor Log
DECLARE_LOG_CATEGORY_EXTERN(LogSensor, Log, All);
//Log during game startup
DECLARE_LOG_CATEGORY_EXTERN(LogGamePlay, Log, All);