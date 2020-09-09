// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProjectJK/Sensor/SensorManager.h"
#include "ProjectJK/Global/TableManager.h"
#include "ProjectJK/Global/WidgetManager.h"
#include "ProjectJK/Global/DataIOManager.h"
#include "ProjectJK/Global/DelegateCollection.h"
#include "JKGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UJKGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UJKGameInstance(const FObjectInitializer& ObjectInitializer);

	static class UJKGameInstance* GetJKGameInstance(class UObject* OutterOwner);
	void Init() override;
	void Shutdown() override;

public:
	UPROPERTY() class USensorManager* SensorManager = nullptr;
	UPROPERTY() class UTableManager* TableManager = nullptr;
	UPROPERTY() class UWidgetManager* WidgetManager = nullptr;
	UPROPERTY() class UDataIOManager* DataIOManager = nullptr;
	UPROPERTY() class UDelegateCollection* DelegateCollection = nullptr;
	
public:
	UPROPERTY()
	bool valueChanged;
	
};
