// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_z3camTest.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Sensor/z3cam/z3camHandler.h"
#include "Kismet/KismetSystemLibrary.h"


void UUP_z3camTest::NativeConstruct()
{
	Super::NativeConstruct();
	BindUIEvent();
	//BindDelegateEvent();
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SensorText = FText::FromString(TEXT(""));
	instance->GetWorld()->GetTimerManager().SetTimer(SensorCheckTickHandler, this, &UUP_z3camTest::StartCheck, .1f, true, 0);
}

void UUP_z3camTest::NativeDestruct()
{
	UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(GetWorld(), SensorCheckTickHandler);
	Super::NativeDestruct();
}

void UUP_z3camTest::NativeTick(const FGeometry & MyGeometry, float InDeltaTime)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	if (instance->valueChanged)
	{
		SetUIbyCallback();
		instance->valueChanged = false;
	}
}

void UUP_z3camTest::BindUIEvent()
{
	if (IsValid(BTN_InitSensor))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_InitSensor);
	}
	if (IsValid(BTN_StartSensor))
	{
		BTN_StartSensor->OnClicked.Clear();
		BTN_StartSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_StartSensor);
	}
	if (IsValid(BTN_StopSensor))
	{
		BTN_StopSensor->OnClicked.Clear();
		BTN_StopSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_StopSensor);
	}
	if (IsValid(BTN_ShutdownSensor))
	{
		BTN_ShutdownSensor->OnClicked.Clear();
		BTN_ShutdownSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_ShutdownSensor);
	}
	if (IsValid(BTN_OneButton))
	{
		BTN_OneButton->OnClicked.Clear();
		BTN_OneButton->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_OneButton);
	}
	if (IsValid(BTN_Driver))
	{
		BTN_Driver->OnClicked.Clear();
		BTN_Driver->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectDriver);
	}
	if (IsValid(BTN_Iron))
	{
		BTN_Iron->OnClicked.Clear();
		BTN_Iron->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectIron);
	}
	if (IsValid(BTN_Putter))
	{
		BTN_Putter->OnClicked.Clear();
		BTN_Putter->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectPutter);
	}
	if (IsValid(BTN_Left))
	{
		BTN_Left->OnClicked.Clear();
		BTN_Left->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectLeft);
	}
	if (IsValid(BTN_Right))
	{
		BTN_Right->OnClicked.Clear();
		BTN_Right->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectRight);
	}
	if (IsValid(BTN_GetVersion))
	{
		BTN_GetVersion->OnClicked.Clear();
		BTN_GetVersion->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_GetVersion);
	}
}

void UUP_z3camTest::BindDelegateEvent()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->DelegateCollection->NewTrajectoryDataSet.Clear();
	instance->DelegateCollection->NewTrajectoryDataSet.AddDynamic(this, &UUP_z3camTest::SetUIbyCallback);

}

void UUP_z3camTest::SetSensorCommandResultText(FString text)
{
	TB_SensorCheckState->SetText(FText::FromString(text));
}

void UUP_z3camTest::SetClubText(FString text)
{
	TB_Club->SetText(FText::FromString(text));
}

void UUP_z3camTest::SetHandText(FString text)
{
	TB_Hand->SetText(FText::FromString(text));
}

void UUP_z3camTest::StartCheck()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	if (!instance->SensorManager->IsSensorConnected())
		return;

	switch (instance->SensorManager->CheckSensorState())
	{
	case ESensorState::E_NULL:
		SensorText = FText::FromString(TEXT("NULL STATE"));
		break;
	case ESensorState::E_READY:
		SensorText = FText::FromString(TEXT("READY STATE"));
		break;
	case ESensorState::E_DISCONNECT:
		SensorText = FText::FromString(TEXT("DISCONNECT STATE"));
		break;
	case ESensorState::E_BIGSHADOW:
		SensorText = FText::FromString(TEXT("BIG SHADOW STATE"));
		break;
	case ESensorState::E_NOBALL:
		SensorText = FText::FromString(TEXT("NO BALL STATE"));
		break;
	case ESensorState::E_LOWACTIVE:
		SensorText = FText::FromString(TEXT("LOW ACTIVE STATE"));
		break;
	default:
		SensorText = FText::FromString(TEXT("READY STATE"));
		break;
	}
	RTB_SensorState->SetText(SensorText);
}

void UUP_z3camTest::SetUIbyCallback()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	FCR2_trajectoryEX trj = instance->DataIOManager->GetTrajectoryData();
	FCR2_shotdataEX sd = instance->DataIOManager->GetShotData();

	if(IsValid(TB_Carry))
		TB_Carry->SetText(FText::AsNumber(trj.carrydistance));
	int32 bs = sd.ballspeedx1000 / 1000;
	TB_BallSpeed->SetText(FText::AsNumber(bs));
	TB_PeakHeight->SetText(FText::AsNumber(trj.peakheight));
}

void UUP_z3camTest::OnClicked_InitSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SetSensorCommandResultText(instance->SensorManager->InitSensor());
}

void UUP_z3camTest::OnClicked_StartSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SetSensorCommandResultText(instance->SensorManager->StartSensor());
}

void UUP_z3camTest::OnClicked_StopSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SetSensorCommandResultText(instance->SensorManager->StopSensor());
}

void UUP_z3camTest::OnClicked_ShutdownSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SetSensorCommandResultText(instance->SensorManager->ShutdownSensor());
}

void UUP_z3camTest::OnClicked_OneButton()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	SetSensorCommandResultText(instance->SensorManager->StartProcess());
}

void UUP_z3camTest::OnClicked_SelectDriver()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_DRIVER;
	SetClubText(FString(TEXT("Driver")));
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectIron()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_IRON7;
	SetClubText(FString(TEXT("Iron")));
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectPutter()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_PUTTER;
	SetClubText(FString(TEXT("Putter")));
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectLeft()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->hand = 1;
	SetHandText(FString(TEXT("Left")));
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectRight()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->hand = 0;
	SetHandText(FString(TEXT("Right")));
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_GetVersion()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	TB_Version->SetText(FText::FromString(instance->SensorManager->GetVersion()));
}
