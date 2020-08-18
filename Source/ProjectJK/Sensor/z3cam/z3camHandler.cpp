// Fill out your copyright notice in the Description page of Project Settings.

#include "z3camHandler.h"
#include "z3camSDK.h"

FString Uz3camHandler::GetVersion()
{
// 	if (!hand)
// 		Init();

	long long p0 = 0; //major
	long long p1 = 0; //minor
	long long p2 = 0; //buildnum

	int cmd = CR2CMD_DLLVERSION;
	int res = (int)z3camSDK::CR2_init(hand, cmd, &p0, &p1, &p2, 0);

	//PrintLog(LineInfo(), res, ShowLog);

	FString version;
	if (res == CR2_OK)
	{
		version = FString::FromInt(p0) + "_" + FString::FromInt(p1) + "_" + FString::FromInt(p2);
		UE_LOG("DllVersion: " + version);
	}
	else
	{
		version = "0_0_0";
		UE_LOG("Get Version Error");
	}

	return version;
}

int Uz3camHandler::SetHeightIncline(int height, int vangleadd)
{
	return 0;
}

int Uz3camHandler::ConfigureCamSensor(int usage)
{
	return 0;
}

int Uz3camHandler::Set_Tee(int usage, float height)
{
	return 0;
}

int Uz3camHandler::Set_Club(int clubcode)
{
	return 0;
}

int Uz3camHandler::Set_Wind(float mag, float dir)
{
	return 0;
}

int Uz3camHandler::Set_MainHand(int _hand)
{
	return 0;
}

int Uz3camHandler::SetTeeState(int p0, int p1)
{
	return 0;
}

int Uz3camHandler::GetSensorState(int &state)
{
	return 0;
}

int Uz3camHandler::AllowArea(int tee, int ground, int putting)
{
	return 0;
}

int Uz3camHandler::CheckBallPosition(FCR2_ballposition &tee, FCR2_ballposition &ground, FCR2_ballposition &putting)
{
	return 0;
}
