// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_PauseButton.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"

void UUP_PauseButton::NativeConstruct()
{
	Super::NativeConstruct();
	BindUIEvent();
}

void UUP_PauseButton::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUP_PauseButton::BindUIEvent()
{
	if (BTN_Pause)
	{
		BTN_Pause->OnClicked.Clear();
		BTN_Pause->OnClicked.AddDynamic(this, &UUP_PauseButton::OnClicked_Pause);
	}
}

void UUP_PauseButton::OnClicked_Pause()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_PauseMenu);
}
