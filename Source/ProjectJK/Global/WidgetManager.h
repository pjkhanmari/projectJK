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

	void ShowUserWidgetCreateAuto(EWidgetBluePrint wbp);
	void ShowUserWidgetCreateAutoForceOrder(EWidgetBluePrint wbp, int32 zOrder);
	UUserWidget* GetUserWidget(EWidgetBluePrint wbp);
	UUserWidget* CreateUserWidget(EWidgetBluePrint wbp);
	void ChangeUIPage(EUIPage PageTogo);
	void ShowUIPage(EUIPage PageTogo);
	EUIPage GetCurrentUP();
	EUIPage GetPrevUP();

public:
	UPROPERTY()
	TMap<EWidgetBluePrint, UUserWidget*> WBP_map;
	UPROPERTY()
	TArray<EUIPage> UP_order;

private:
	UPROPERTY()
	int32 zOrderAuto;
};
