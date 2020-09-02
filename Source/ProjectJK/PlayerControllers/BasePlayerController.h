// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABasePlayerController(const FObjectInitializer& ObjectInitializer);
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	virtual void						ProcessPlayerInput(const float DeltaTime, const bool bGamePaused) override;
	virtual void						SetupInputComponent() override;
};
