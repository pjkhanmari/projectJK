// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameModeBase.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Sensor/SensorManager.h"
#include "ProjectJK/Global/WidgetManager.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "Kismet/KismetMathLibrary.h"

void ATestGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_TestUI);
	//instance->SensorManager->StartSensor();
// 	for (FPhysicalSurfaceName sn : UPhysicsSettings::Get()->PhysicalSurfaces)
// 		UE_LOG(LogSensor, Log, TEXT("%s"), *(sn.Name.ToString()));
	
	for (int32 i = 0; i < 3; i++)
		SpawnTestPawn();
}

void ATestGameModeBase::EndPlay(const EEndPlayReason::Type EndReason)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->SensorManager->ShutdownSensor();
	Super::EndPlay(EndReason);
}

void ATestGameModeBase::NumberOne()
{
	UE_LOG(LogTemp, Log, TEXT("korea number one!!"));
}

void ATestGameModeBase::NumberTwo()
{
	UE_LOG(LogTemp, Log, TEXT("korea number two!!"));
}

void ATestGameModeBase::NumberThree()
{
	UE_LOG(LogTemp, Log, TEXT("korea number three!!"));
}

void ATestGameModeBase::NumberFour()
{
	UE_LOG(LogTemp, Log, TEXT("korea number four!!"));
}

void ATestGameModeBase::SpawnTestPawn()
{
	Pawns.Emplace(GetWorld()->SpawnActor<APawn>(PawnForSpawn, GetRandomLocation(), FRotator::ZeroRotator));
}

FVector ATestGameModeBase::GetRandomLocation()
{
	return UKismetMathLibrary::MakeVector(UKismetMathLibrary::RandomFloatInRange(17000.f, 18000.f),
		UKismetMathLibrary::RandomFloatInRange(1000.f, 2000.f),
		500.f);
}

// 
// void ATestGameModeBase::Tick(float DeltaSeconds)
// {
// 	UJKGameInstance* instance = GAMEINSTANCE(this);
// 	ESensorState state = instance->SensorManager->CheckSensorState();
// }
