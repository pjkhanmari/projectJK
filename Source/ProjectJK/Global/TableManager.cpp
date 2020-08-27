// Fill out your copyright notice in the Description page of Project Settings.


#include "TableManager.h"

void UTableManager::Initialize()
{
	DT_WidgetDir = LoadTableWIthDir("DataTable'/Game/DATA/Tables/WidgetDir.WidgetDir'");
}

FWidgetDirTableRow * UTableManager::GetWidgetDirTableRow(FName key)
{
	FWidgetDirTableRow* pRow = DT_WidgetDir->FindRow<FWidgetDirTableRow>(key, FString(""));
	return pRow;
}

UDataTable * UTableManager::LoadTableWIthDir(const FName & dir)
{
	if (dir == NAME_None) return NULL;

	UObject* DataTableObject = (StaticLoadObject(UDataTable::StaticClass(), NULL, *dir.ToString()));
	UDataTable* DataTablePtr = Cast< UDataTable >(DataTableObject);

	return DataTablePtr;
}
