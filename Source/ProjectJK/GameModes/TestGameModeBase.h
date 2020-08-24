// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectJK/ProjectJKGameModeBase.h"
#include "TestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API ATestGameModeBase : public AProjectJKGameModeBase
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type reason) override;

	void Tick(float DeltaSeconds) override;
};
