// Fill out your copyright notice in the Description page of Project Settings.


#include "DataIOManager.h"
#include "ProjectJK/JKGameInstance.h"
#include "ProjectJK/ProjectJK.h"
#include "ProjectJK/Global/DelegateCollection.h"

void UDataIOManager::Initialize()
{
// 	if (CurrShotData == nullptr)
// 		CurrShotData = new FCR2_shotdataEX();
}

void UDataIOManager::SetShotData(FCR2_shotdataEX data)
{
	CurrShotData = data;
}

FCR2_shotdataEX UDataIOManager::GetShotData()
{
	return CurrShotData;
}

void UDataIOManager::SetTrajectoryData(FCR2_trajectoryEX data)
{
	CurrTrajectoryData = data;
}

FCR2_trajectoryEX UDataIOManager::GetTrajectoryData()
{
	return CurrTrajectoryData;
}
