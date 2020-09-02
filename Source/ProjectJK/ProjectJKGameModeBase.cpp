// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectJKGameModeBase.h"
#include "ProjectJK/PlayerControllers/BasePlayerController.h"

AProjectJKGameModeBase::AProjectJKGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerControllerClass = ABasePlayerController::StaticClass();
}

void AProjectJKGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectJKGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
