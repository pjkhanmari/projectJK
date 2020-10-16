// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_DebugShotp.h"
#include "../JKGameInstance.h"
#include "../ProjectJK.h"
#include "../Sensor/z3cam/z3camStructures/CR2_shotdata.h"
#include "../Sensor/SensorManager.h"
#include "../Sensor/z3cam/z3camHandler.h"

void UUP_DebugShotp::NativeConstruct()
{
	Super::NativeConstruct();

	BindUIEvent();
}

void UUP_DebugShotp::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUP_DebugShotp::BindUIEvent()
{
	if (BTN_DebugShot)
	{
		BTN_DebugShot->OnClicked.Clear();
		BTN_DebugShot->OnClicked.AddDynamic(this, &UUP_DebugShotp::OnClickedDebugShot);
	}
}

void UUP_DebugShotp::OnClickedDebugShot()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	if (instance->SensorManager->IsSensorConnected())
	{
		FCR2_shotdataEX* sd = new FCR2_shotdataEX();
		sd->ballspeedx1000 = FCString::Atoi(*ETB_BallSpeed->Text.ToString());
		sd->azimuthX1000 = FCString::Atoi(*ETB_Azimuth->Text.ToString());
		sd->inclineX1000 = FCString::Atoi(*ETB_Incline->Text.ToString());
		sd->backspinX1000 = FCString::Atoi(*ETB_BackSpin->Text.ToString());
		sd->sidespinX1000 = FCString::Atoi(*ETB_SideSpin->Text.ToString());
		sd->clubspeedX1000 = FCString::Atoi(*ETB_ClubSpeed->Text.ToString());
		sd->faceangleX1000 = FCString::Atoi(*ETB_ClubFaceAngle->Text.ToString());
		sd->clubpathX1000 = FCString::Atoi(*ETB_ClubPath->Text.ToString());

		instance->SensorManager->handler->CR2_CALLBACKFUNC1(nullptr, 16, sd, 1, 1234);
	}
}
