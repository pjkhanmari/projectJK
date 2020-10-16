// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_TestUI.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"
#include <Engine/EngineBaseTypes.h>
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#include "UObject/Linker.h"

void UUP_TestUI::NativeConstruct()
{
	Super::NativeConstruct();
	BindUIEvent();
	//UEditorEngine* const EditorEngine = CastChecked<UEditorEngine>(GAMEINSTANCE(this)->GetEngine());
	FURL url = FURL(TEXT("World'/GameBaseProcess/GameModeTestMap.GameModeTestMap'"));
	//url = FURL(NULL, *EditorEngine->BuildPlayWorldURL(TEXT("World'/GameBaseProcess/GameModeTestMap.GameModeTestMap'"), false, FString()), TRAVEL_Absolute);
	//url.Map = TEXT("World'/GameBaseProcess/GameModeTestMap.GameModeTestMap'");
	this->GetWorld()->SetGameMode(url);
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
	if (IsValid(BTN_Load_LandCheck))
	{
		BTN_Load_LandCheck->OnClicked.Clear();
		BTN_Load_LandCheck->OnClicked.AddDynamic(this, &UUP_TestUI::OnClick_Btn_LoadLandCheck);
	}
}

void UUP_TestUI::OnClick_Btn_Loadz3camUI()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_z3camTest);
}
void UUP_TestUI::OnClick_Btn_LoadLandCheck()
{
	UJKGameInstance* instance = GAMEINSTANCE(this);
	instance->WidgetManager->ChangeUIPage(EUIPage::UIPage_LandCheck);
}
