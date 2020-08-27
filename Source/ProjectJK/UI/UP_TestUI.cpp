// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_TestUI.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"


void UUP_TestUI::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUP_TestUI::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUP_TestUI::BindUIEvent()
{
	if (IsValid(BTN_Load_z3camUI))
	{
		BTN_Load_z3camUI->OnClicked.Clear();
		BTN_Load_z3camUI->OnClicked.AddDynamic(this, &UUP_TestUI::OnClick_Btn_Loadz3camUI);
	}
}

void UUP_TestUI::OnClick_Btn_Loadz3camUI()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_z3camTest);
}
