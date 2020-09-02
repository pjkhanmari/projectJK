// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/Widget.h"
#include "Components/TextBlock.h"
#include "Components/RichTextBlock.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"

UENUM(BlueprintType)
enum class EUIPage : uint8
{
	UIPage_None = 0,
	UIPage_TestUI = 1,
	UIPage_z3camTest = 2,
	UIPage_PauseMenu = 3,
};


UENUM(BlueprintType)
enum class EWidgetBluePrint : uint8
{
	WBP_None = 0,
	WBP_TestUI = 1,
	WBP_z3camTest = 2,
	WBP_PauseMenu = 3,
	WBP_PauseButton = 4
};
