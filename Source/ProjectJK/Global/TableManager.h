// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "ProjectJK/Global/DataTableStructs.h"
#include "TableManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJK_API UTableManager : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();

	FWidgetDirTableRow* GetWidgetDirTableRow(FName key);

private:
	UDataTable* LoadTableWIthDir(const FName& dir);

public:
	UDataTable* DT_WidgetDir;
};
