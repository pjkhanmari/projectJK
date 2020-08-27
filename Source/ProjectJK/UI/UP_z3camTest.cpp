// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_z3camTest.h"
#include "ProjectJK/ProjectJK.h"


void UUP_z3camTest::NativeConstruct()
{
	Super::NativeConstruct();
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
	instance->SensorManager->select();
}

void UUP_z3camTest::OnClicked_SelectIron()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->StartSensor();
}

void UUP_z3camTest::OnClicked_SelectPutter()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->StartSensor();
}

void UUP_z3camTest::OnClicked_SelectLeft()
{
}

void UUP_z3camTest::OnClicked_SelectRight()
{
}
