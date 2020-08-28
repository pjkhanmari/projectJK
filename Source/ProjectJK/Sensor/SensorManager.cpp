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

void USensorManager::StopSensor()
{
	if (isSensorConnected)
		handler->Stop();
}

void USensorManager::ShutdownSensor()
{
	if (isSensorConnected)
	{
		if (handler->Stop())
			handler->Shutdown();
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

void USensorManager::SetProperty()
{
	int32 useTee = 0; 
	float teeHeight = 0;

	if (club == CR2CLUB_DRIVER)
	{
		useTee = 1;
		teeHeight = 0.055;
	}
	//tee set
	handler->Set_Tee(useTee, teeHeight);
	//club set
	handler->Set_Club(club);
	//wind set
	handler->Set_Wind(windMag, windDir);
	//checking area set
	switch (club)
	{
	case CR2CLUB_DRIVER:
		handler->AllowArea(1, 0, 0);
		break;
	case CR2CLUB_IRON1:
		handler->AllowArea(1, 1, 0);
		break;
	case CR2CLUB_PUTTER:
		handler->AllowArea(0, 0, 1);
		break;
	default:
		break;
	}
	//main hand set
	handler->Set_MainHand(hand);
	//altitude set
	handler->Set_Altitude(altitude);
	//calculate option set
	handler->Set_ClubdataCalOption(calculateClubOption);
}

void USensorManager::StartProcess()
{
	InitSensor();
	StartSensor();
	SetProperty();
	RestartSensor();
}

