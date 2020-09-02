// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

ABasePlayerController::ABasePlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->bShowMouseCursor = true;
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ABasePlayerController::ProcessPlayerInput(const float DeltaTime, const bool bGamePaused)
{
	Super::ProcessPlayerInput(DeltaTime, bGamePaused);
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
