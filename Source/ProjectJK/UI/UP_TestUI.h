// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProjectJK/Global/DefineUI.h"
#include "UP_TestUI.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_TestUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	void NativeDestruct() override;

	void BindUIEvent();

public:
	UFUNCTION()
	void OnClick_Btn_Loadz3camUI();
	UFUNCTION()
	void OnClick_Btn_LoadLandCheck();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_TestUI)
	UButton* BTN_Load_z3camUI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_TestUI)
	UButton* BTN_Load_LandCheck;
};
