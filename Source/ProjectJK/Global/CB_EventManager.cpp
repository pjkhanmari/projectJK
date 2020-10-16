// Fill out your copyright notice in the Description page of Project Settings.


#include "CB_EventManager.h"
#include "../JKGameInstance.h"
#include "../ProjectJK.h"

// Sets default values
ACB_EventManager::ACB_EventManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACB_EventManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACB_EventManager::Tick(float DeltaTime)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);

	Super::Tick(DeltaTime);

	if (instance->isShotEvent)
	{
		UE_LOG(LogSensor, Log, TEXT(""))
		instance->DelegateCollection->NewTrajectoryDataSet.Broadcast();
		instance->isShotEvent = false;
	}
}

