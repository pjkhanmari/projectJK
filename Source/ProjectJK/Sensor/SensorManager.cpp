// Fill out your copyright notice in the Description page of Project Settings.

#include "SensorManager.h"
#include "ProjectJK/Sensor/z3cam/z3camHandler.h"

void USensorManager::Initialize()
{
	handler = NewObject<Uz3camHandler>((UObject*)GetTransientPackage(), Uz3camHandler::StaticClass());
}

FString USensorManager::InitSensor()
{
	if (isSensorConnected)
		return "Already Connected";

	isSensorConnected = handler->Init();
	if (isSensorConnected)
		return "Sensor Init Success";
	else
		return "Sensor Init Failed";
}

FString USensorManager::StartSensor()
{
	if (isSensorConnected)
		return handler->Start();
	else
		return "Sensor No Connection";
}

FString USensorManager::RestartSensor()
{
	if (isSensorConnected)
		return handler->Restart();
	else
		return "Sensor No Connection";
}

FString USensorManager::StopSensor()
{
	bool stopSuccess = false;
	if (isSensorConnected)
		stopSuccess = handler->Stop();

	if (stopSuccess)
		return "Sensor Stop Success";
	else
		return "Sensor Stop Failed";
}

FString USensorManager::ShutdownSensor()
{
	if (isSensorConnected)
	{
		if (handler->Stop())
			return handler->Shutdown();
	}
	return "Sensor No Connection";
}

ESensorState USensorManager::CheckSensorState()
{
	switch (handler->GetSensorState())
	{
	case 0:
		return ESensorState::E_NULL;
	case 1:
		return ESensorState::E_READY;
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

FString USensorManager::GetVersion()
{
	return handler->GetVersion();
}

void USensorManager::SetProperty()
{
	int64 useTee = 0; 
	int64 teeHeight = 0;

	if (club == CR2CLUB_DRIVER)
	{
		useTee = 1;
		teeHeight = 55;//mm
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
bool USensorManager::IsSensorConnected()
{
	return isSensorConnected;
}
// 
// void USensorManager::StartSensorCheck()
// {
// 	UJKGameInstance* instance = GAMEINSTANCE(this);
// 	if(isSensorConnected)
// 		instance->GetWorld()->GetTimerManager().SetTimer(SensorCheckTickHandler, this, instance->SensorManager->CheckSensorState())
// }

