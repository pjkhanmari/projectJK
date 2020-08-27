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
	UIPage_z3camTest = 2
};
