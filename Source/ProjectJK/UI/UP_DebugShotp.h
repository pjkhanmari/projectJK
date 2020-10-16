// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "UP_DebugShotp.generated.h"

class UEditableTextBox;
class UButton;

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_DebugShotp : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	void NativeDestruct() override;

	void BindUIEvent();

public:
	UFUNCTION()
	void OnClickedDebugShot();

public:
	UPROPERTY()
	UEditableTextBox *ETB_BallSpeed;
	UPROPERTY()
	UEditableTextBox *ETB_Azimuth;
	UPROPERTY()
	UEditableTextBox *ETB_Incline;
	UPROPERTY()
	UEditableTextBox *ETB_BackSpin;
	UPROPERTY()
	UEditableTextBox *ETB_SideSpin;
	UPROPERTY()
	UEditableTextBox *ETB_ClubSpeed;
	UPROPERTY()
	UEditableTextBox *ETB_ClubFaceAngle;
	UPROPERTY()
	UEditableTextBox *ETB_ClubPath;
	UPROPERTY()
	UButton* BTN_DebugShot;
};
