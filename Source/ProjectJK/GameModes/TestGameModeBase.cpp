// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameModeBase.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Sensor/SensorManager.h"
#include "ProjectJK/Global/WidgetManager.h"

void ATestGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_TestUI);
	//instance->SensorManager->StartSensor();
}

void ATestGameModeBase::EndPlay(const EEndPlayReason::Type EndReason)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->ShutdownSensor();
	Super::EndPlay(EndReason);
}
// 
// void ATestGameModeBase::Tick(float DeltaSeconds)
// {
// 	UJKGameInstance* instance = GAMEINSTANCE(this);
// 	ESensorState state = instance->SensorManager->CheckSensorState();
// }
