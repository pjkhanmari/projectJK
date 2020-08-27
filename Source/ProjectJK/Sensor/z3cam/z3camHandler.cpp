// Fill out your copyright notice in the Description page of Project Settings.

#include "z3camHandler.h"
#include "z3camSDK.h"
#include "ProjectJK/ProjectJK.h"


Uz3camHandler::Uz3camHandler()
{
	Initialize();
}

Uz3camHandler::~Uz3camHandler()
{

}

#if defined(_WIN64)
int Uz3camHandler::CR2_CALLBACKFUNC(void* h, uint32 status, FCR2_shotdata *psd, int64 userparam)
#else
int Uz3camHandler::CR2_CALLBACKFUNC(void* h, uint32 status, FCR2_shotdata *psd, int32 userparam)
#endif
{
	return 0;
}

#if defined(_WIN64)
int32 Uz3camHandler::CR2_CALLBACKFUNC1(void* h, uint32 status, void* hsd, uint32 cbfuncid, int64 userparam)
#else
int32 Uz3camHandler::CR2_CALLBACKFUNC1(void* h, uint32 status, void* hsd, uint32 cbfuncid, int32 userparam)
#endif
{
	UE_LOG(LogSensor, Log, TEXT("[CALLBACK] func1 \n"));
	UE_LOG(LogSensor, Log, TEXT("hand : %p"), h);
	UE_LOG(LogSensor, Log, TEXT("status : 0x%0x"), status);
	UE_LOG(LogSensor, Log, TEXT("hsd : 0x%p"), hsd);
	UE_LOG(LogSensor, Log, TEXT("cbfunc1_id : %d"), cbfuncid);
	UE_LOG(LogSensor, Log, TEXT("userparam : 0x%0x"), userparam);

	switch (status) 
	{
		case CR2STATUS_DISCONNECT:
		{
			UE_LOG(LogSensor, Log, TEXT("[CALLBACK] DISCONNECT!"));
			break;
		}
		case CR2STATUS_TRIALSHOT:
		{
			UE_LOG(LogSensor, Log, TEXT("[CALLBACK] TRIAL SHOT! Discard it!"));
			break;
		}
		case CR2STATUS_GOODSHOT:
		{
			UE_LOG(LogSensor, Log, TEXT("[CALLBACK] Good SHOT!"));
			CheckBallPosition();

			if (cbfuncid == 1) {
				FCR2_shotdataEX *psdEX1;

				//--
				psdEX1 = (FCR2_shotdataEX*)hsd;

				printf("-----------\n");
				{
					FCR2_guid *pguid;
					pguid = &psdEX1->shotguid;
					UE_LOG(LogSensor, Log, TEXT("guid: %08x-%04x-%04x-%02x-%02x-%02x-%02x-%02x-%02x-%02x-%02x"),
						(int)pguid->Data1,
						(int)pguid->Data2,
						(int)pguid->Data3,
						(int)pguid->Data4[0],
						(int)pguid->Data4[1],
						(int)pguid->Data4[2],
						(int)pguid->Data4[3],
						(int)pguid->Data4[4],
						(int)pguid->Data4[5],
						(int)pguid->Data4[6],
						(int)pguid->Data4[7]);
				}
	// 			printf("category: %d\n", psdEX1->category);
	// 			printf("right0left1: %d\n", psdEX1->rightlefthanded);
	// 			printf("ball pos: %08lf %08lf %08lf\n", psdEX1->xposx1000 / 1000.0, psdEX1->yposx1000 / 1000.0, psdEX1->zposx1000 / 1000.0);
	// 			printf("---\n");
	// 
	// 			printf("vmag : %10lf\n", psdEX1->ballspeedx1000 / 1000.0);
	// 			printf("incline : %10lf\n", psdEX1->inclineX1000 / 1000.0);
	// 			printf("azimuth : %10lf\n", psdEX1->azimuthX1000 / 1000.0);
	// 			printf("spincalc method : %d\n", psdEX1->spincalc_method);
	// 			printf("assurance_spin: %d\n", psdEX1->assurance_spin);
	// 			printf("backspin     : %10lf [rpm]\n", psdEX1->backspinX1000 / 1000.0);
	// 			printf("sidespin     : %10lf [rpm]\n", psdEX1->sidespinX1000 / 1000.0);
	// 			printf("rollspin     : %10lf [rpm]\n", psdEX1->rollspinX1000 / 1000.0);
	// 			printf("---\n");
	// 
	// 			printf("clubcalc method             : %d\n", psdEX1->clubcalc_method);
	// 			printf("assurance_clubspeed         : %d\n", psdEX1->assurance_clubspeed);
	// 			printf("assurance_clubpath          : %d\n", psdEX1->assurance_clubpath);
	// 			printf("assurance_faceangle         : %d\n", psdEX1->assurance_faceangle);
	// 			printf("assurance_attackangle       : %d\n", psdEX1->assurance_attackangle);
	// 			printf("assurance_loftangle         : %d\n", psdEX1->assurance_loftangle);
	// 			printf("assurance_lieangle          : %d\n", psdEX1->assurance_lieangle);
	// 			printf("assurance_faceimpactLateral : %d\n", psdEX1->assurance_faceimpactLateral);
	// 			printf("assurance_faceimpactVertical: %d\n", psdEX1->assurance_faceimpactVertical);
	// 
	// 
	// 			printf("clubspeed                   : %10lf \n", psdEX1->clubspeedX1000 / 1000.0);
	// 			printf("clubpathX1000               : %10lf \n", psdEX1->clubpathX1000 / 1000.0);
	// 			printf("faceangleX1000              : %10lf \n", psdEX1->faceangleX1000 / 1000.0);
	// 			printf("attackangleX1000            : %10lf \n", psdEX1->attackangleX1000 / 1000.0);
	// 			printf("loftangleX1000              : %10lf \n", psdEX1->loftangleX1000 / 1000.0);
	// 			printf("lieangleX1000               : %10lf \n", psdEX1->lieangleX1000 / 1000.0);
	// 			printf("faceimpactLateralX1000      : %10lf \n", psdEX1->faceimpactVerticalX1000 / 1000.0);
	// 			printf("---\n");
			}
			else {
				UE_LOG(LogSensor, Log, TEXT("cbfunc_id : %d is NOT supported yet.."), cbfuncid);
			}
			break;
		}
		default:
		{
			UE_LOG(LogSensor, Log, TEXT("[CALLBACK] what?\n"));
			break;
		}
	}

	return CR2_OK;
}

void Uz3camHandler::Initialize()
{
	bool success = false;
#if (_WIN64)
	success = Uz3camSDK::importDLL("z3cam", "z3camAdapt64.dll");
#else
	success = Uz3camSDK::importDLL("z3cam", "z3camAdapt.dll");
#endif

	if (success)
	{
		UE_LOG(LogSensor, Log, TEXT("Import DLL success"));
		if (Uz3camSDK::import_initMethod())
		{
			UE_LOG(LogSensor, Log, TEXT("Import init method success"));
		}
		else
		{
			UE_LOG(LogSensor, Log, TEXT("Import delete method failed"));
		}
		if (Uz3camSDK::import_deleteMethod())
		{
			UE_LOG(LogSensor, Log, TEXT("Import delete method success"));
		}
		else
		{
			UE_LOG(LogSensor, Log, TEXT("Import init method failed"));
		}
		if (Uz3camSDK::import_commandMethod())
		{
			UE_LOG(LogSensor, Log, TEXT("Import command method success"));
		}
		else
		{
			UE_LOG(LogSensor, Log, TEXT("Import command method failed"));
		}
	}
	else
		UE_LOG(LogSensor, Log, TEXT("Import DLL failed"));
}

bool Uz3camHandler::Init()
{
	int cmd = CR2SENSORBOARD_N1P2;

	hand.ccode.Reset(CLIENT_CODE_LENGTH);
	for (int i = 0; i < CLIENT_CODE_LENGTH; i++)
		hand.ccode.Emplace(0);

#if defined(_WIN64)
	hand.h = Uz3camSDK::CR2_init(cmd, 0, (int64)&hand.ccode[0], IANA_OPMODE_DEFAULT, 0, 0);
#else
	hand.h = Uz3camSDK::CR2_init(cmd, 0, (int32)&hand.ccode[0], IANA_OPMODE_CAM, 0, 0);
#endif

	bool result = hand.h ? true : false;
	return result;
}

void Uz3camHandler::Start()
{
	std::function<int32(Uz3camHandler&, void* h, uint32 status, void* hsd, uint32 cbfuncid, int64 userparam)> cb = &Uz3camHandler::CR2_CALLBACKFUNC1;
	int cmd, res;

#if defined(_WIN64)
	int64 userparam;

	userparam = 1234;			// Whatever..
	//int64 p0 = reinterpret_cast<int64>(cb);
	int64 p0 = (int64)&cb;
	int64 p1 = (int64)1;
	int64 p2 = (int64)userparam;

#else
	int32 userparam; 

	userparam = 1234;			// Whatever..
	p0 = (int32)(&CR2_CALLBACKFUNC1);
	p1 = (int32)1;
	p2 = (int32)userparam;
#endif

	cmd = CR2CMD_OPERATION_START1;
	res = Uz3camSDK::CR2_command(hand.h, cmd, p0, p1, p2, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::Restart()
{
	int cmd = CR2CMD_OPERATION_RESTART;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, 0, 0, 0, 0);
	PrintResult(cmd, res);
}

bool Uz3camHandler::Stop()
{
	int cmd = CR2CMD_OPERATION_STOP;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, 0, 0, 0, 0);

	PrintResult(cmd, res);

	bool result = res == CR2_OK ? true : false;
	return result;
}

void Uz3camHandler::Shutdown()
{
	int res = Uz3camSDK::CR2_delete(hand.h);
	if (res == CR2_OK)
	{
		UE_LOG(LogSensor, Log, TEXT("CR2_delete is success"));
	}
	else
	{
		UE_LOG(LogSensor, Log, TEXT("CR2_delete is failed"));
	}
}

FString Uz3camHandler::GetVersion()
{
// 	if (!hand)
// 		Init();

	int64 p0 = 0; //major
	int64 p1 = 0; //minor
	int64 p2 = 0; //buildnum

	int cmd = CR2CMD_DLLVERSION;
	hand.h = Uz3camSDK::CR2_init(CR2SENSORBOARD_N1P2, cmd, p0, p1, p2, 0);

	FString version;
	if (hand.h)
		version = FString::FromInt(p0) + "_" + FString::FromInt(p1) + "_" + FString::FromInt(p2);
	else
		version = "0_0_0";

	return version;
}

void Uz3camHandler::SetHeightIncline(int64 height, int64 vangleadd)
{
	int cmd = CR2CMD_SENSORCONFIG;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, height, vangleadd, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::ConfigureCamSensor(int64 usage)
{
	int cmd = CR2CMD_CAMSENSORCONFIG;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, usage, 0, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::Set_Tee(int64 usage, float height)
{
	int cmd = CR2CMD_USETEE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, usage, (int64)height, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
	{
		FString msg = (usage == 1) ? "Set use tee" : "Set don't use tee";
		UE_LOG(LogSensor, Log, TEXT("%s"), *msg);
	}
}

void Uz3camHandler::Set_Club(int64 clubcode)
{
	int cmd = CR2CMD_USECLUB;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, clubcode, 0, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Club code : %s"), clubcode);
}

void Uz3camHandler::Set_Wind(float mag, float dir)
{
	int cmd = CR2CMD_WIND;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, (int64)mag, (int64)dir, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Wind mag : %s, Wind dir : %s"), mag, dir);
}

void Uz3camHandler::Set_MainHand(int64 _hand)
{
	int cmd = CR2CMD_SETRIGHTLEFT;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, _hand, 0, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::SetTeeState(int64 param1, int64 param2)
{
	int cmd = CR2CMD_SETTEESTATE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, param1, param2, 0, 0);
	PrintResult(cmd, res);
}

int Uz3camHandler::GetSensorState()
{
	int sensor_status = 0;
	int64 p0 = (int64)&sensor_status;
	int cmd = CR2CMD_SENSORSTATUS;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, p0, 0, 0, 0);
	PrintResult(cmd, res);

	return sensor_status;
}

void Uz3camHandler::AllowArea(int64 tee, int64 ground, int64 putting)
{
	int cmd = CR2CMD_AREAALLOW;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, tee, ground, putting, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::CheckBallPosition()
{
	FCR2_ballposition  TeeBallPos;
	FCR2_ballposition  IronBallPos;
	FCR2_ballposition  PuttingBallPos;

#if defined(_WIN64)                         // For 64bit SDK
	int64 p0 = (int64)& TeeBallPos;
	int64 p1 = (int64)& IronBallPos;
	int64 p2 = (int64)& PuttingBallPos;
#else
	int32 p0 = (int32)& TeeBallPos;
	int32 p1 = (int32)& IronBallPos;
	int32 p2 = (int32)& PuttingBallPos;
#endif
	int cmd = CR2CMD_BALLPOSITION;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, p0, p1, p2, 0);
	PrintResult(cmd, res);
	
	if (res == CR2_OK) {
		if (TeeBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Tee area!"));
		}
		else if (IronBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Iron area!"));
		}
		else if (PuttingBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Putting area!"));
		}
	}
}

void Uz3camHandler::PrintResult(int32 title, int32 result, bool showLog)
{
	if (showLog)
	{
		switch (title)
		{
		case CR2CMD_OPERATION_START1:
		{
			switch (result)
			{
			case CR2_OK:
				UE_LOG(LogSensor, Log, TEXT("CR2_OK"));
			default:
				UE_LOG(LogSensor, Log, TEXT("?? : ??"));
			}
			break;
		}
		default:
			UE_LOG(LogSensor, Log, TEXT("??"));
		}

	}
		//UE_LOG(LogSensor, Log, TEXT("%s : %s"), GET_VARIABLE_NAME(title), GET_VARIABLE_NAME(result));
}
// 
// FString Uz3camHandler::GetResultString(int result)
// {
// 	
// }


