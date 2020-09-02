// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectJKGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API AProjectJKGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AProjectJKGameModeBase(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
};
