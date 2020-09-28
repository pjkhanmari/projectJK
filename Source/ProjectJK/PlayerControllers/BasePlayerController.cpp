// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "../GameModes/TestGameModeBase.h"

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
// 	if (this->GetWorld()->GetMapName() == "NewMap")
// 	{
		UE_LOG(LogTemp, Log, TEXT("Bind action for new map"));
		InputComponent->BindAction("NumberOne", IE_Pressed, (ATestGameModeBase*)this->GetWorld()->GetAuthGameMode(), &ATestGameModeBase::NumberOne);
		InputComponent->BindAction("NumberTwo", IE_Pressed, (ATestGameModeBase*)this->GetWorld()->GetAuthGameMode(), &ATestGameModeBase::NumberTwo);
		InputComponent->BindAction("NumberThree", IE_Pressed, (ATestGameModeBase*)this->GetWorld()->GetAuthGameMode(), &ATestGameModeBase::NumberThree);
		InputComponent->BindAction("NumberFour", IE_Pressed, (ATestGameModeBase*)this->GetWorld()->GetAuthGameMode(), &ATestGameModeBase::NumberFour);
//	}
}
