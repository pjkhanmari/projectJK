// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataTableStructs.generated.h" 


/**
 * 
 */
USTRUCT(BlueprintType)
struct FWidgetDirTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WidgetDir)
		FString WidgetDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WidgetDir)
		int32 Zorder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WidgetDir)
		TSubclassOf<UUserWidget> BlueprintClass;
};
