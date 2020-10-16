// Fill out your copyright notice in the Description page of Project Settings.

#include "z3camHandler.h"
#include "z3camSDK.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_trajectory.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_trajectoryEX.h"
#include "ProjectJK/ProjectJK.h"
#include "../../../../../UE4/Engine/Source/Runtime/Engine/Public/Subsystems/Subsystem.h"
#include "../../../../../UE4/Engine/Source/Runtime/Core/Public/Containers/Array.h"
#include "Kismet/GameplayStatics.h"


Uz3camHandler::Uz3camHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Initialize();
}

Uz3camHandler::~Uz3camHandler()
{
	DeInitialize();
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
// 	UE_LOG(LogSensor, Log, TEXT("[CALLBACK] func1"));
// 	UE_LOG(LogSensor, Log, TEXT("hand : %p"), h);
// 	UE_LOG(LogSensor, Log, TEXT("status : 0x%0x"), status);
// 	UE_LOG(LogSensor, Log, TEXT("hsd : 0x%p"), hsd);
// 	UE_LOG(LogSensor, Log, TEXT("cbfunc1_id : %d"), cbfuncid);
// 	UE_LOG(LogSensor, Log, TEXT("userparam : 0x%0x"), userparam);

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
 
// 				printf("-----------\n");
// 				{
// 					FCR2_guid *pguid;
// 					pguid = &psdEX1->shotguid;
// 					UE_LOG(LogSensor, Log, TEXT("guid: %08x-%04x-%04x-%02x-%02x-%02x-%02x-%02x-%02x-%02x-%02x"),
// 						(int)pguid->Data1,
// 						(int)pguid->Data2,
// 						(int)pguid->Data3,
// 						(int)pguid->Data4[0],
// 						(int)pguid->Data4[1],
// 						(int)pguid->Data4[2],
// 						(int)pguid->Data4[3],
// 						(int)pguid->Data4[4],
// 						(int)pguid->Data4[5],
// 						(int)pguid->Data4[6],
// 						(int)pguid->Data4[7]);
// 				}

				UJKGameInstance* instance = GAMEINSTANCE(this);
				instance->DataIOManager->SetShotData(*psdEX1);
				FCR2_shotdata* psd = new FCR2_shotdata();
				psd->ballspeedX10 = psdEX1->ballspeedx1000 / 100;
				psd->azimuthX10 = psdEX1->azimuthX1000 / 100;
				psd->inclineX10 = psdEX1->inclineX1000 / 100;
				psd->backspin = psdEX1->backspinX1000 / 1000;
				psd->sidespin = psdEX1->sidespinX1000 / 1000;
				psd->clubspeed_BX10 = psdEX1->clubspeedX1000 / 100;
				psd->clubfaceangleX10 = psdEX1->faceangleX1000 / 100;
				psd->clubpathX10 = psdEX1->clubpathX1000 / 100;

				if (CalCulateTrajectory(psd) == CR2_OK)
					instance->isShotEvent = true;
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
	importSuccess = false;
#if (_WIN64)
	importSuccess = Uz3camSDK::importDLL("z3cam", "z3camAdapt64.dll");
#else
	importSuccess = Uz3camSDK::importDLL("z3cam", "z3camAdapt.dll");
#endif

	if (importSuccess)
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

void Uz3camHandler::DeInitialize()
{
	if (importSuccess)
		Uz3camSDK::freeDLL();
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

FString Uz3camHandler::Start()
{
	hand.cb = &Uz3camHandler::CR2_CALLBACKFUNC1;
	int cmd, res;

#if defined(_WIN64)
	int64 userparam;

	userparam = 1234;			// Whatever..
	//int64 p0 = reinterpret_cast<int64>(cb);
	int64 p0 = (int64)&cbWrapper;
	int64 p1 = (int64)1;
	int64 p2 = (int64)userparam;

#else
	int32 userparam; 

	userparam = 1234;			// Whatever..
	int32 p0 = (int32)&(hand.cb);
	int32 p1 = (int32)1;
	int32 p2 = (int32)userparam;
#endif

	cmd = CR2CMD_OPERATION_START1;
	res = Uz3camSDK::CR2_command(hand.h, cmd, p0, p1, p2, 0);
	return PrintResult(TEXT("CR2CMD_OPERATION_START1"), res);
}

FString Uz3camHandler::Restart()
{
	int cmd = CR2CMD_OPERATION_RESTART;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, 0, 0, 0, 0);
	return PrintResult(TEXT("CR2CMD_OPERATION_RESTART"), res);
}

bool Uz3camHandler::Stop()
{
	int cmd = CR2CMD_OPERATION_STOP;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, 0, 0, 0, 0);

	PrintResult(TEXT("CR2CMD_OPERATION_STOP"), res);

	bool result = res == CR2_OK ? true : false;
	return result;
}

FString Uz3camHandler::Shutdown()
{
	int res = Uz3camSDK::CR2_delete(hand.h);
	FString msg;
	if (res == CR2_OK)
		msg = "CR2_delete is success";
	else
		msg = "CR2_delete is failed";
	UE_LOG(LogSensor, Log, TEXT("%s"), *msg)
	return msg;
}

FString Uz3camHandler::GetVersion()
{
#if defined(_WIN64)
	int64 major = 0; //major
	int64 minor = 0; //minor
	int64 buildnum = 0; //buildnum

	int64 p0 = (int64)&major;
	int64 p1 = (int64)&minor;
	int64 p2 = (int64)&buildnum;
#else
	int32 major = 0; //major
	int32 minor = 0; //minor
	int32 buildnum = 0; //buildnum

	int32 p0 = (int32)&major;
	int32 p1 = (int32)&minor;
	int32 p2 = (int32)&buildnum;
#endif

	int cmd = CR2CMD_DLLVERSION;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, p0, p1, p2, 0);

	FString version;
	if (res == CR2_OK)
		version = FString::FromInt(major) + "_" + FString::FromInt(minor) + "_" + FString::FromInt(buildnum);
	else
		version = "0_0_0";

	return version;
}

#if(_WIN64)
void Uz3camHandler::SetHeightIncline(int64 height, int64 vangleadd)
#else
void Uz3camHandler::SetHeightIncline(int32 height, int32 vangleadd)
#endif
{
	int cmd = CR2CMD_SENSORCONFIG;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, height, vangleadd, 0, 0);
	PrintResult(TEXT("CR2CMD_SENSORCONFIG"), res);
}

#if(_WIN64)
void Uz3camHandler::ConfigureCamSensor(int64 usage)
#else
void Uz3camHandler::ConfigureCamSensor(int32 usage)
#endif
{
	int cmd = CR2CMD_CAMSENSORCONFIG;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, usage, 0, 0, 0);
	PrintResult(TEXT("CR2CMD_CAMSENSORCONFIG"), res);
}

#if(_WIN64)
void Uz3camHandler::Set_Tee(int64 usage, int64 height)
#else
void Uz3camHandler::Set_Tee(int32 usage, int32 height)
#endif
{
	int cmd = CR2CMD_USETEE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, usage, height, 0, 0);
	PrintResult(TEXT("CR2CMD_USETEE"), res);
	if (res == CR2_OK)
	{
		FString msg = (usage == 1) ? "Set use tee" : "Set don't use tee";
		UE_LOG(LogSensor, Log, TEXT("%s"), *msg);
	}
}

#if(_WIN64)
void Uz3camHandler::Set_Club(int64 clubcode)
#else
void Uz3camHandler::Set_Club(int32 clubcode)
#endif
{
	int cmd = CR2CMD_USECLUB;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, clubcode, 0, 0, 0);
	PrintResult(TEXT("CR2CMD_USECLUB"), res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Club code : %d"), clubcode);
}

#if(_WIN64)
void Uz3camHandler::Set_Wind(int64 mag, int64 dir)
#else
void Uz3camHandler::Set_Wind(int32 mag, int32 dir)
#endif

{
	int cmd = CR2CMD_WIND;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, mag, dir, 0, 0);
	PrintResult(TEXT("CR2CMD_WIND"), res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Wind mag : %d, Wind dir : %d"), mag, dir);
}

#if(_WIN64)
void Uz3camHandler::Set_MainHand(int64 _hand)
#else
void Uz3camHandler::Set_MainHand(int32 _hand)
#endif
{
	int cmd = CR2CMD_SETRIGHTLEFT;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, _hand, 0, 0, 0);
	PrintResult(TEXT("CR2CMD_SETRIGHTLEFT"), res);
}

#if(_WIN64)
void Uz3camHandler::Set_Altitude(int64 altitude)
#else
void Uz3camHandler::Set_Altitude(int32 altitude)
#endif
{
	int cmd = CR2CMD_SET_ALTITUDE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, altitude, 0, 0, 0);
	PrintResult(TEXT("CR2CMD_SET_ALTITUDE"), res);
}

#if(_WIN64)
void Uz3camHandler::Set_ClubdataCalOption(int64 option)
#else
void Uz3camHandler::Set_ClubdataCalOption(int32 option)
#endif
{
	int cmd = CR2CMD_SET_CLUBMODE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, option, 0, 0, 0);
	PrintResult(TEXT("CR2CMD_SET_CLUBMODE"), res);
}

#if(_WIN64)
void Uz3camHandler::SetTeeState(int64 param1, int64 param2)
#else
void Uz3camHandler::SetTeeState(int32 param1, int32 param2)
#endif
{
	int cmd = CR2CMD_SETTEESTATE;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, param1, param2, 0, 0);
	PrintResult(TEXT("CR2CMD_SETTEESTATE"), res);
}

int Uz3camHandler::GetSensorState()
{
	int sensor_status = 0;
#if(_WIN64)
	int64 p0 = (int64)&sensor_status;
#else
	int32 p0 = (int32)&sensor_status;
#endif
	int cmd = CR2CMD_SENSORSTATUS;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, p0, 0, 0, 0);
	//PrintResult(TEXT("CR2CMD_SENSORSTATUS"), res);

	return sensor_status;
}

#if(_WIN64)
void Uz3camHandler::AllowArea(int64 tee, int64 ground, int64 putting)
#else
void Uz3camHandler::AllowArea(int32 tee, int32 ground, int32 putting)
#endif
{
	int cmd = CR2CMD_AREAALLOW;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, tee, ground, putting, 0);
	PrintResult(TEXT("CR2CMD_AREAALLOW"), res);
}

int Uz3camHandler::CalCulateTrajectory(FCR2_shotdata* data)
{
	FCR2_trajectory trj, *ptrj;
	FCR2_trajectoryEX trjEX, *ptrjEX;

	ptrj = &trj;
	ptrjEX = &trjEX;

#if defined (_WIN64)
	int64 p0 = (int64)data;
	int64 p1 = (int64)ptrj;
	int64 p2 = (int64)ptrjEX;
#else
	int32 p0 = (int32)data;
	int32 p1 = (int32)ptrj;
	int32 p2 = (int32)ptrjEX;
#endif // (_WIN64)
	int cmd = CR2CMD_CALC_TRAJECTORY;
	int res = Uz3camSDK::CR2_command(hand.h, cmd, p0, p1, p2, 0);

	PrintResult(TEXT("CR2CMD_CALC_TRAJECTORY"), res);

	UJKGameInstance* instance = GAMEINSTANCE(this);
	if(res == CR2_OK)
		instance->DataIOManager->SetTrajectoryData(trjEX);
	return res;
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
	PrintResult(TEXT("CR2CMD_BALLPOSITION"), res);
	
	if (res == CR2_OK) {
		if (TeeBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Tee area!"))
		}
		else if (IronBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Iron area!"))
		}
		else if (PuttingBallPos.shotresult) 
		{
			UE_LOG(LogSensor, Log, TEXT("Last shot was occurred in Putting area!"))
		}
	}
}

FString Uz3camHandler::PrintResult(const FString title, int result)
{
	FString resultMsg;
	switch (result)
	{
	case CR2_OK:
		resultMsg = "CR2_OK";
		break;
	case CR2_ERR_GENERAL:
		resultMsg = "CR2_ERR_GENERAL";
		break;
	case CR2_ERR_BADHANDLE:
		resultMsg = "CR2_ERR_BADHANDLE";
		break;
	case CR2_ERR_UNSUPPORTED_CMD:
		resultMsg = "CR2_ERR_UNSUPPORTED_CMD";
		break;
	case CR2_ERR_BADPARAM:
		resultMsg = "CR2_ERR_BADPARAM";
		break;
	case CR2_ERR_CAM_RESERVE_FAIL:
		resultMsg = "CR2_ERR_CAM_RESERVE_FAIL";
		break;
	case CR2_ERR_CAM_NOT_OWNER:
		resultMsg = "CR2_ERR_CAM_NOT_OWNER";
		break;
	case CR2_ERR_CAM_CONFIG_FAIL:
		resultMsg = "CR2_ERR_CAM_CONFIG_FAIL";
		break;
	default:
		resultMsg = "???";
		break;
	}
	FString msg = title + " command result is : " + resultMsg;
	if (showLog)
		UE_LOG(LogSensor, Log, TEXT("%s"), *msg);
	return msg;
}

int32 cbWrapper(void * h, uint32 status, void * hsd, uint32 cbfuncid, int64 userparam)
{
	UJKGameInstance* instance = GAMEINSTANCE(nullptr);
	return GAMEINSTANCE(nullptr)->SensorManager->handler->CR2_CALLBACKFUNC1(h, status, hsd, cbfuncid, userparam);

}
