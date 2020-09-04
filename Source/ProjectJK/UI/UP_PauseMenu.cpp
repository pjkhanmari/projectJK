// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_PauseMenu.h"
#include "../JKGameInstance.h"
#include "../ProjectJK.h"
#include "Kismet/GameplayStatics.h"

void UUP_PauseMenu::NativeConstruct()
{
	Super::NativeConstruct();
	BindUIEvent();
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
	UJKGameInstance* instance = GAMEINSTANCE(this);
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	EUIPage prevPage = instance->WidgetManager->GetPrevUP();
	instance->WidgetManager->ChangeUIPage(prevPage);
}

void UUP_PauseMenu::OnClicked_MainMenu()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_TestUI);
}

void UUP_PauseMenu::OnClicked_Quit()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
#if WITH_EDITOR
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
#else
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
#endif
}
