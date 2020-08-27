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

	void BindUIEvent();

	void OnClicked_InitSensor();
	void OnClicked_StartSensor();
	void OnClicked_StopSensor();
	void OnClicked_ShutdownSensor();
	void OnClicked_SelectDriver();
	void OnClicked_SelectIron();
	void OnClicked_SelectPutter();
	void OnClicked_SelectLeft();
	void OnClicked_SelectRight();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_InitSensor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_StartSensor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_StopSensor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_ShutdownSensor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_Driver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_Iron;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_Putter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UUP_z3camTest)
	UButton* BTN_Right;
	
};
