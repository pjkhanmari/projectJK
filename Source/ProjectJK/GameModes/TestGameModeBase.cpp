// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameModeBase.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Sensor/SensorManager.h"
#include "ProjectJK/Global/WidgetManager.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "../Actors/GolfBall.h"

void ATestGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_TestUI);
// 	for (FPhysicalSurfaceName sn : UPhysicsSettings::Get()->PhysicalSurfaces)
// 		UE_LOG(LogSensor, Log, TEXT("%s"), *(sn.Name.ToString()));
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Pawns.Emplace(pc->GetPawn());
// 	for (int32 i = 0; i < 3; i++)
// 		SpawnTestPawn();

	UE_LOG(LogTemp, Log, TEXT("My Pawns count is %d"), Pawns.Num());
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
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pc->Possess(Pawns[0]);
}

void ATestGameModeBase::NumberTwo()
{
	UE_LOG(LogTemp, Log, TEXT("korea number two!!"));
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pc->Possess(Pawns[1]);
}

void ATestGameModeBase::NumberThree()
{
	UE_LOG(LogTemp, Log, TEXT("korea number three!!"));
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pc->Possess(Pawns[2]);
}

void ATestGameModeBase::NumberFour()
{
	UE_LOG(LogTemp, Log, TEXT("korea number four!!"));
	auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pc->Possess(Pawns[3]);
}

void ATestGameModeBase::SpawnTestPawn()
{
	Pawns.Emplace(GetWorld()->SpawnActor<AGolfBall>(PawnForSpawn, GetRandomLocation(), FRotator::ZeroRotator));
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
