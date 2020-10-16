// Fill out your copyright notice in the Description page of Project Settings.

#include "UP_LandCheck.h"

void UUP_LandCheck::NativeConstruct()
{
	Super::NativeConstruct();
	LandChecker = (ALandCheckActor*)GetWorld()->SpawnActor(ALandCheckActor::StaticClass());

	BindUIEvent();
}

void UUP_LandCheck::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUP_LandCheck::BindUIEvent()
{
	if (IsValid(BTN_LineCheck))
	{
		BTN_LineCheck->OnClicked.Clear();
		BTN_LineCheck->OnClicked.AddDynamic(this, &UUP_LandCheck::OnClicked_LineCheck);
	}
	if (IsValid(BTN_ObjectCheck))
	{
		BTN_ObjectCheck->OnClicked.Clear();
		BTN_ObjectCheck->OnClicked.AddDynamic(this, &UUP_LandCheck::OnClicked_ObjectCheck);
	}
	if (IsValid(BTN_SphereCheck))
	{
		BTN_SphereCheck->OnClicked.Clear();
		BTN_SphereCheck->OnClicked.AddDynamic(this, &UUP_LandCheck::OnClicked_SphereCheck);
	}
	if (IsValid(CB_IsDebug))
	{
		CB_IsDebug->OnCheckStateChanged.Clear();
		CB_IsDebug->OnCheckStateChanged.AddDynamic(this, &UUP_LandCheck::OnStateChanged_IsDebug);
	}
}

void UUP_LandCheck::OnClicked_LineCheck()
{
	LandChecker->m_nLandCheckType = LAND_CHECK_TYPE::LINE;
}

void UUP_LandCheck::OnClicked_ObjectCheck()
{
	LandChecker->m_nLandCheckType = LAND_CHECK_TYPE::OBJECT;
}

void UUP_LandCheck::OnClicked_SphereCheck()
{
	LandChecker->m_nLandCheckType = LAND_CHECK_TYPE::SPHERE;
}

void UUP_LandCheck::OnStateChanged_IsDebug(bool isChecked)
{
	LandChecker->m_isDebug = isChecked;
}
