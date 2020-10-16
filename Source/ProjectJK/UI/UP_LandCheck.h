// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "../Actors/LandCheckActor.h"
#include "UP_LandCheck.generated.h"

class ALandCheckActor;

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_LandCheck : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	void NativeDestruct() override;

	void BindUIEvent();

public:
	UFUNCTION()
	void OnClicked_LineCheck();
	UFUNCTION()
	void OnClicked_ObjectCheck();
	UFUNCTION()
	void OnClicked_SphereCheck();
	UFUNCTION()
	void OnStateChanged_IsDebug(bool isChecked);

public:
	UPROPERTY()
	UButton* BTN_LineCheck;
	UPROPERTY()
	UButton* BTN_ObjectCheck;
	UPROPERTY()
	UButton* BTN_SphereCheck;
	UPROPERTY()
	UCheckBox* CB_IsDebug;

private:
	UPROPERTY()
	ALandCheckActor* LandChecker;

};
