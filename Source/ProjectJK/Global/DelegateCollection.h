// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DelegateCollection.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_NoParam);

UCLASS()
class PROJECTJK_API UDelegateCollection : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize();
	
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = DelegateCollection)
	FDelegate_NoParam NewTrajectoryDataSet;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = DelegateCollection)
	FDelegate_NoParam FlyEnd;
	
};
