// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProjectJK/Global/DefineUI.h"
#include "WidgetManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UWidgetManager : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();

	void ShowUserWidgetCreateAuto(EUIPage eUP);
	void ShowUserWidgetCreateAutoForceOrder(EUIPage eUP, int32 zOrder);
	UUserWidget* GetUserWidget(EUIPage eUP);
	UUserWidget* CreateUserWidget(EUIPage eUP);
	void ChangeUIPage(EUIPage PageTogo);
	EUIPage GetCurrentUP();
	EUIPage GetPrevUP();

public:
	UPROPERTY()
	TMap<EUIPage, UUserWidget*> UP_map;
	UPROPERTY()
	TArray<EUIPage> UP_order;

private:
	UPROPERTY()
	int32 zOrderAuto;
};
