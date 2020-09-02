// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UP_PauseButton.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_PauseButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	void NativeDestruct() override;
	
	void BindUIEvent();

public:
	UFUNCTION()
	void OnClicked_Pause();

public:
	UPROPERTY()
	UButton* BTN_Pause;
};
