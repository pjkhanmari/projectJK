// Fill out your copyright notice in the Description page of Project Settings.

#include "z3camHandler.h"
#include "z3camSDK.h"
#include "ProjectJK/ProjectJK.h"


int Uz3camHandler::CR2_CALLBACKFUNC(HAND h, U32 status, FCR2_shotdata *psd, I32 userparam)
{
	return 0;
}

int Uz3camHandler::CR2_CALLBACKFUNC1(HAND h, U32 status, HAND hsd, U32 cbfuncid, I64 userparam)
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


// 	if (h != NULL) {				// Yes.. restart shot.
// 		U32 cmd;
// 		CR2_result_t res;
// 
// 		cmd = CR2CMD_OPERATION_RESTART;
// 		res = CR2_command(h, cmd, 0, 0, 0, 0);
// 	}

	return CR2_OK;
}

FString Uz3camHandler::GetVersion()
{
// 	if (!hand)
// 		Init();

	I64 p0 = 0; //major
	I64 p1 = 0; //minor
	I64 p2 = 0; //buildnum

	int cmd = CR2CMD_DLLVERSION;
	hand = (HAND)z3camSDK::CR2_init(CR2SENSORBOARD_N1P2, cmd, p0, p1, p2, 0);

	FString version;
	if (hand)
		version = FString::FromInt(p0) + "_" + FString::FromInt(p1) + "_" + FString::FromInt(p2);
	else
		version = "0_0_0";

	return version;
}

void Uz3camHandler::SetHeightIncline(I64 height, I64 vangleadd)
{
	int cmd = CR2CMD_SENSORCONFIG;
	int res = z3camSDK::CR2_command(hand, cmd, height, vangleadd, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::ConfigureCamSensor(I64 usage)
{
	int cmd = CR2CMD_CAMSENSORCONFIG;
	int res = z3camSDK::CR2_command(hand, cmd, usage, 0, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::Set_Tee(I64 usage, float height)
{
	int cmd = CR2CMD_USETEE;
	int res = z3camSDK::CR2_command(hand, cmd, usage, (I64)height, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
	{
		FString msg = (usage == 1) ? "Set use tee" : "Set don't use tee";
		UE_LOG(LogSensor, Log, TEXT("%s"), *msg);
	}
}

void Uz3camHandler::Set_Club(I64 clubcode)
{
	int cmd = CR2CMD_USECLUB;
	int res = z3camSDK::CR2_command(hand, cmd, clubcode, 0, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Club code : %s"), clubcode);
}

void Uz3camHandler::Set_Wind(float mag, float dir)
{
	int cmd = CR2CMD_WIND;
	int res = z3camSDK::CR2_command(hand, cmd, (I64)mag, (I64)dir, 0, 0);
	PrintResult(cmd, res);
	if (res == CR2_OK)
		UE_LOG(LogSensor, Log, TEXT("Wind mag : %s, Wind dir : %s"), mag, dir);
}

void Uz3camHandler::Set_MainHand(I64 _hand)
{
	int cmd = CR2CMD_SETRIGHTLEFT;
	int res = z3camSDK::CR2_command(hand, cmd, _hand, 0, 0, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::SetTeeState(I64 p0, I64 p1)
{
	int cmd = CR2CMD_SETTEESTATE;
	int res = z3camSDK::CR2_command(hand, cmd, p0, p1, 0, 0);
	PrintResult(cmd, res);
}

int Uz3camHandler::GetSensorState()
{
	int sensor_status = 0;
	I64 p0 = (I64)&sensor_status;
	int cmd = CR2CMD_SENSORSTATUS;
	int res = z3camSDK::CR2_command(hand, cmd, p0, 0, 0, 0);
	PrintResult(cmd, res);

	return sensor_status;
}

void Uz3camHandler::AllowArea(I64 tee, I64 ground, I64 putting)
{
	int cmd = CR2CMD_AREAALLOW;
	int res = z3camSDK::CR2_command(hand, cmd, tee, ground, putting, 0);
	PrintResult(cmd, res);
}

void Uz3camHandler::CheckBallPosition()
{
#if defined(_WIN64)
	I64 p0, p1, p2;
#else
	I32 p0, p1, p2;
#endif
	FCR2_ballposition  TeeBallPos;
	FCR2_ballposition  IronBallPos;
	FCR2_ballposition  PuttingBallPos;

#if defined(_WIN64)                         // For 64bit SDK
	p0 = (I64)& TeeBallPos;
	p1 = (I64)& IronBallPos;
	p2 = (I64)& PuttingBallPos;
#else
	p0 = (I32)& TeeBallPos;
	p1 = (I32)& IronBallPos;
	p2 = (I32)& PuttingBallPos;
#endif
	int cmd = CR2CMD_BALLPOSITION;
	int res = z3camSDK::CR2_command(hand, cmd, p0, p1, p2, 0);
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

void Uz3camHandler::PrintResult(int title, int result, bool showLog)
{
	if (showLog)
		UE_LOG(LogSensor, Log, TEXT("%s : %s"), GET_VARIABLE_NAME(title), GET_VARIABLE_NAME(result));
}


