// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManager.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/JKGameInstance.h"

void UWidgetManager::Initialize()
{
	UP_map.Reset();
	UP_order.Empty();
	zOrderAuto = 0;
}

void UWidgetManager::ShowUserWidgetCreateAuto(EUIPage eUP)
{
	UUserWidget* widget = GetUserWidget(eUP);
	if (!IsValid(widget))
		widget = CreateUserWidget(eUP);

	if (!widget->IsInViewport())
	{
		widget->AddToViewport(zOrderAuto);
		widget->SetVisibility(ESlateVisibility::Visible);
	}
	zOrderAuto++;
}

void UWidgetManager::ShowUserWidgetCreateAutoForceOrder(EUIPage eUP, int32 zOrder)
{
	UUserWidget* widget = GetUserWidget(eUP);
	if (!IsValid(widget))
		widget = CreateUserWidget(eUP);

	if (!widget->IsInViewport())
	{
		widget->AddToViewport(zOrder);
		widget->SetVisibility(ESlateVisibility::Visible);
	}
}

UUserWidget* UWidgetManager::GetUserWidget(EUIPage eUP)
{
	if(UP_map.Contains(eUP))
		UUserWidget* widget = *UP_map.Find(eUP);

	return nullptr;
}

UUserWidget* UWidgetManager::CreateUserWidget(EUIPage eUP)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	FName key = FName(*FString::FromInt((int32)eUP));
	FWidgetDirTableRow* pRow = instance->TableManager->GetWidgetDirTableRow(key);
//	return nullptr;
	UClass* subclass = (pRow->BlueprintClass).Get();
	UUserWidget* widget = CreateWidget<UUserWidget>(instance, pRow->BlueprintClass);
	if (widget)
	{
		UP_map.Emplace(eUP, widget);
		return widget;
	}
	else
		return nullptr;
}

void UWidgetManager::ChangeUIPage(EUIPage PageTogo)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);

	EUIPage PrevPage = GetPrevUP();
	EUIPage CurrentPage = GetCurrentUP();

	if (PageTogo == CurrentPage)
		return;

	if (PageTogo == PrevPage)
		UP_order.Pop();

	UP_order.Push(PageTogo);

	for (auto it = UP_map.CreateIterator(); it; ++it)
	{
		UUserWidget* up = (*it).Value;
		if (IsValid(up))
		{
			if (up->IsInViewport())
			{
				up->RemoveFromViewport();
				up = nullptr;
				break;
			}
		}
	}
	zOrderAuto = 0;

	instance->WidgetManager->ShowUserWidgetCreateAuto(PageTogo);
	//instance->WidgetManager->ShowUserWidget(PageTogo);
}

EUIPage UWidgetManager::GetCurrentUP()
{
	if (UP_order.Num() > 0)
		return UP_order.Last();
	else
		return EUIPage::UIPage_None;

}

EUIPage UWidgetManager::GetPrevUP()
{
	if (UP_order.Num() > 1)
		return UP_order[UP_order.Num() - 2];
	else
		return EUIPage::UIPage_None;
}
 
