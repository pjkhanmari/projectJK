// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_z3camTest.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Sensor/z3cam/z3camHandler.h"


void UUP_z3camTest::NativeConstruct()
{
	Super::NativeConstruct();
	BindUIEvent();
}

void UUP_z3camTest::NativeDestruct()
{
	Super::NativeDestruct();
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
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_StartSensor);
	}
	if (IsValid(BTN_StopSensor))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_StopSensor);
	}
	if (IsValid(BTN_ShutdownSensor))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_ShutdownSensor);
	}
	if (IsValid(BTN_Driver))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectDriver);
	}
	if (IsValid(BTN_Iron))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectIron);
	}
	if (IsValid(BTN_Putter))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectPutter);
	}
	if (IsValid(BTN_Left))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectLeft);
	}
	if (IsValid(BTN_Right))
	{
		BTN_InitSensor->OnClicked.Clear();
		BTN_InitSensor->OnClicked.AddDynamic(this, &UUP_z3camTest::OnClicked_SelectRight);
	}
}

void UUP_z3camTest::OnClicked_InitSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->InitSensor();
}

void UUP_z3camTest::OnClicked_StartSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->StartSensor();
}

void UUP_z3camTest::OnClicked_StopSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->StopSensor();
}

void UUP_z3camTest::OnClicked_ShutdownSensor()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->ShutdownSensor();
}

void UUP_z3camTest::OnClicked_SelectDriver()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_DRIVER;
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectIron()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_IRON7;
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectPutter()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->club = CR2CLUB_PUTTER;
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectLeft()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->hand = 1;
	instance->SensorManager->SetProperty();
}

void UUP_z3camTest::OnClicked_SelectRight()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->hand = 0;
	instance->SensorManager->SetProperty();
}
