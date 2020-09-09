// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProjectJK/Global/DefineUI.h"
#include "UP_z3camTest.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UUP_z3camTest : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;
	void NativeDestruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void BindUIEvent();
	void BindDelegateEvent();
	void SetSensorCommandResultText(FString text);
	void SetClubText(FString text);
	void SetHandText(FString text);

public:
	UFUNCTION()
	void StartCheck();
	UFUNCTION()
	void SetUIbyCallback();
	UFUNCTION()
	void OnClicked_InitSensor();
	UFUNCTION()
	void OnClicked_StartSensor();
	UFUNCTION()
	void OnClicked_StopSensor();
	UFUNCTION()
	void OnClicked_ShutdownSensor();
	UFUNCTION()
	void OnClicked_OneButton();
	UFUNCTION()
	void OnClicked_SelectDriver();
	UFUNCTION()
	void OnClicked_SelectIron();
	UFUNCTION()
	void OnClicked_SelectPutter();
	UFUNCTION()
	void OnClicked_SelectLeft();
	UFUNCTION()
	void OnClicked_SelectRight();
	UFUNCTION()
	void OnClicked_GetVersion();

public:
	//Button
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_InitSensor;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_StartSensor;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_StopSensor;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_ShutdownSensor;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_OneButton;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Driver;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Iron;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Putter;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Left;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Right;
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_GetVersion;
	//textblock
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* RTB_SensorState;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_SensorCheckState;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_Club;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_Hand;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_Version;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_Carry;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_BallSpeed;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TB_PeakHeight;


private:
	UPROPERTY()
	FTimerHandle SensorCheckTickHandler;
	UPROPERTY()
	FText SensorText;
};
