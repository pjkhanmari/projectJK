// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_PauseMenu.h"

void UUP_PauseMenu::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUP_PauseMenu::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUP_PauseMenu::BindUIEvent()
{
	if (BTN_Resume)
	{
		BTN_Resume->OnClicked.Clear();
		BTN_Resume->OnClicked.AddDynamic(this, &UUP_PauseMenu::OnClicked_Resume);
	}
	if (BTN_MainMenu)
	{
		BTN_MainMenu->OnClicked.Clear();
		BTN_MainMenu->OnClicked.AddDynamic(this, &UUP_PauseMenu::OnClicked_MainMenu);
	}
	if (BTN_Quit)
	{
		BTN_Quit->OnClicked.Clear();
		BTN_Quit->OnClicked.AddDynamic(this, &UUP_PauseMenu::OnClicked_Quit);
	}
}

void UUP_PauseMenu::OnClicked_Resume()
{
}

void UUP_PauseMenu::OnClicked_MainMenu()
{
}

void UUP_PauseMenu::OnClicked_Quit()
{
}
