// Fill out your copyright notice in the Description page of Project Settings.

#include "JKGameInstance.h"
#include "ProjectJK.h"

PROJECTJK_API UJKGameInstance* Instance = nullptr;

UJKGameInstance::UJKGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	UE_LOG(LogGamePlay, Log, TEXT("Initialize game instance - %s "), *(this->GetName()));

#ifdef WITH_EDITOR
	Instance = this;
#endif // WITH_EDITOR

}

UJKGameInstance * UJKGameInstance::GetJKGameInstance(UObject * OutterOwner)
{
#ifdef WITH_EDITOR
	if (OutterOwner == nullptr || OutterOwner->GetWorld() == nullptr)
	{
		//		UE_LOG(LogGamePlay, Log, TEXT("OutterOwner == nullptr or OutterOwner->GetWorld() == nullptr"));
		return Instance;
	}

	UJKGameInstance* instance = Cast<UJKGameInstance>(OutterOwner->GetWorld()->GetGameInstance());
	//if (ensure(instance == nullptr))
	if(instance == nullptr)
	{
		UE_LOG(LogGamePlay, Error, TEXT("GameInstance == nullptr"));
		return Instance;
	}
	else
		return instance;
#else
	return Instance;
#endif
}

void UJKGameInstance::Init()
{
	Instance = this;
	SensorManager = NewObject<USensorManager>((UObject*)GetTransientPackage(), USensorManager::StaticClass());
	SensorManager->Initialize();
	TableManager = NewObject<UTableManager>((UObject*)GetTransientPackage(), UTableManager::StaticClass());
	TableManager->Initialize();
	WidgetManager= NewObject<UWidgetManager>((UObject*)GetTransientPackage(), UWidgetManager::StaticClass());
	WidgetManager->Initialize();
	DataIOManager = NewObject<UDataIOManager>((UObject*)GetTransientPackage(), UDataIOManager::StaticClass());
	DataIOManager->Initialize();
	DelegateCollection = NewObject<UDelegateCollection>((UObject*)GetTransientPackage(), UDelegateCollection::StaticClass());
	DelegateCollection->Initialize();

	valueChanged = false;

	Super::Init();
}

void UJKGameInstance::Shutdown()
{
	SensorManager->ShutdownSensor();
	SensorManager->ConditionalBeginDestroy();
	TableManager->ConditionalBeginDestroy();
	WidgetManager->ConditionalBeginDestroy();
	DataIOManager->ConditionalBeginDestroy();
	DelegateCollection->ConditionalBeginDestroy();
	Super::Shutdown();
}
