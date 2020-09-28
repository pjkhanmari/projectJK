// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManager.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/JKGameInstance.h"

void UWidgetManager::Initialize()
{
	WBP_map.Reset();
	UP_order.Empty();
	zOrderAuto = 0;
}

void UWidgetManager::ShowUserWidgetCreateAuto(EWidgetBluePrint wbp)
{
	UUserWidget* widget = GetUserWidget(wbp);
	if (!IsValid(widget))
		widget = CreateUserWidget(wbp);

	if (!widget->IsInViewport())
	{
		widget->AddToViewport(zOrderAuto);
		widget->SetVisibility(ESlateVisibility::Visible);
	}
	zOrderAuto++;
}

void UWidgetManager::ShowUserWidgetCreateAutoForceOrder(EWidgetBluePrint wbp, int32 zOrder)
{
	UUserWidget* widget = GetUserWidget(wbp);
	if (!IsValid(widget))
		widget = CreateUserWidget(wbp);

	if (!widget->IsInViewport())
	{
		widget->AddToViewport(zOrder);
		widget->SetVisibility(ESlateVisibility::Visible);
	}
}

UUserWidget* UWidgetManager::GetUserWidget(EWidgetBluePrint wbp)
{
	if(WBP_map.Contains(wbp))
		UUserWidget* widget = *WBP_map.Find(wbp);

	return nullptr;
}

UUserWidget* UWidgetManager::CreateUserWidget(EWidgetBluePrint wbp)
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	FName key = FName(*FString::FromInt((int32)wbp));
	FWidgetDirTableRow* pRow = instance->TableManager->GetWidgetDirTableRow(key);
//	return nullptr;
	//UClass* subclass = (pRow->BlueprintClass).Get();
	UUserWidget* widget = CreateWidget<UUserWidget>(instance, pRow->BlueprintClass);
	if (widget)
	{
		WBP_map.Emplace(wbp, widget);
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

	for (auto it = WBP_map.CreateIterator(); it; ++it)
	{
		UUserWidget* up = (*it).Value;
		if (IsValid(up))
		{
			if (up->IsInViewport())
			{
				up->RemoveFromViewport();
				up = nullptr;
			}
		}
	}
	zOrderAuto = 0;

	ShowUIPage(PageTogo);
}

void UWidgetManager::ShowUIPage(EUIPage PageTogo)
{
	switch (PageTogo)
	{
		case EUIPage::UIPage_None:
		{
			break;
		}
		case EUIPage::UIPage_TestUI:
		{
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_TestUI);
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_PauseButton);
			break;
		}
		case EUIPage::UIPage_z3camTest:
		{
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_z3camTest);
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_PauseButton);
			break;
		}
		case EUIPage::UIPage_PauseMenu:
		{
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_PauseMenu);
			break;
		}
		case EUIPage::UIPage_LandCheck:
		{
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_LandCheck);
			ShowUserWidgetCreateAuto(EWidgetBluePrint::WBP_PauseButton);
			break;
		}
	}
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
 
