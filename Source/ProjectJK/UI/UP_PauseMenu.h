// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UP_PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_PauseMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	void NativeDestruct() override;

	void BindUIEvent();

public:
	UFUNCTION()
	void OnClicked_Resume();
	UFUNCTION()
	void OnClicked_MainMenu();
	UFUNCTION()
	void OnClicked_Quit();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_PauseMenu)
	UButton* BTN_Resume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_PauseMenu)
	UButton* BTN_MainMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_PauseMenu)
	UButton* BTN_Quit;
};
