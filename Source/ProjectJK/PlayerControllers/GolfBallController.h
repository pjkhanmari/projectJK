// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../GameModes/TestGameModeBase.h"
#include "GolfBallController.generated.h"

class ATestGameModeBase;

/**
 * 
 */
UCLASS()
class PROJECTJK_API AGolfBallController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGolfBallController(const FObjectInitializer& ObjectInitializer);
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void ProcessPlayerInput(const float DeltaTime, const bool bGamePaused) override;
	void SetupInputComponent() override;

public:
	UFUNCTION()
	void OnClickedNumberOne();
	UFUNCTION()
	void OnClickedNumberTwo();
	UFUNCTION()
	void OnClickedNumberThree();
	UFUNCTION()
	void OnClickedNumberFour();
	UFUNCTION()
	void OnClickedMoveForward(float AxisValue);
	UFUNCTION()
	void OnClickedTurnRight(float AxisValue);
	UFUNCTION()
	void OnClickedKeyboardC();
	UFUNCTION()
	void OnMouseWheelDown();
	UFUNCTION()
	void OnMouseWheelUp();

private:
	ATestGameModeBase* testGMB;
};
