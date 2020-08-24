// Fill out your copyright notice in the Description page of Project Settings.

#include "SensorManager.h"
#include "ProjectJK/Sensor/z3cam/z3camHandler.h"

void USensorManager::Initialize()
{
	handler = NewObject<Uz3camHandler>((UObject*)GetTransientPackage(), Uz3camHandler::StaticClass());
}

void USensorManager::InitSensor()
{
	if (isSensorConnected)
		return;

	isSensorConnected = handler->Init();
}

void USensorManager::StartSensor()
{
	if (isSensorConnected)
		handler->Start();
}

void USensorManager::RestartSensor()
{
	if (isSensorConnected)
		handler->Restart();
}

void USensorManager::ShutdownSensor()
{
	if (isSensorConnected)
	{
		if (handler->Stop())
		{
			handler->Shutdown();
		}
	}
}

ESensorState USensorManager::CheckSensorState()
{
	switch (handler->GetSensorState())
	{
	case 0:
		return ESensorState::E_NULL;
	case 1:
		return ESensorState::E_READY;
	case 16:
		return ESensorState::E_GOODSHOT;
	case 17:
		return ESensorState::E_TRIALSHOT;
	case 256:
		return ESensorState::E_DISCONNECT;
	case 257:
		return ESensorState::E_BIGSHADOW;
	case 258:
		return ESensorState::E_NOBALL;
	case 259:
		return ESensorState::E_LOWACTIVE;
	default:
		return ESensorState::E_STATUSERR;
	}
}
