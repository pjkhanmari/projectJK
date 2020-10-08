// Fill out your copyright notice in the Description page of Project Settings.


#include "GolfBallController.h"
#include "../Actors/GolfBall.h"

AGolfBallController::AGolfBallController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->bShowMouseCursor = true;
}

void AGolfBallController::BeginPlay()
{
	Super::BeginPlay();

	testGMB = (ATestGameModeBase*)this->GetWorld()->GetAuthGameMode();
}

void AGolfBallController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AGolfBallController::ProcessPlayerInput(const float DeltaTime, const bool bGamePaused)
{
	Super::ProcessPlayerInput(DeltaTime, bGamePaused);
}

void AGolfBallController::SetupInputComponent()
{
	Super::SetupInputComponent();
// 	if (this->GetWorld()->GetMapName() == "NewMap")
// 	{
	UE_LOG(LogTemp, Log, TEXT("Bind action for new map"));
	InputComponent->BindAction("NumberOne", IE_Pressed, this, &AGolfBallController::OnClickedNumberOne);
	InputComponent->BindAction("NumberTwo", IE_Pressed, this, &AGolfBallController::OnClickedNumberTwo);
	InputComponent->BindAction("NumberThree", IE_Pressed, this, &AGolfBallController::OnClickedNumberThree);
	InputComponent->BindAction("NumberFour", IE_Pressed, this, &AGolfBallController::OnClickedNumberFour);

	InputComponent->BindAction("CameraZoomIn", IE_Pressed, this, &AGolfBallController::OnMouseWheelUp);
	InputComponent->BindAction("CameraZoomOut", IE_Pressed, this, &AGolfBallController::OnMouseWheelDown);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AGolfBallController::OnClickedKeyboardC);

	InputComponent->BindAxis("MoveForward", this, &AGolfBallController::OnClickedMoveForward);
	InputComponent->BindAxis("TurnRight", this, &AGolfBallController::OnClickedTurnRight);
//	}
}

void AGolfBallController::OnClickedNumberOne()
{
	if (testGMB)
		testGMB->NumberOne();
}

void AGolfBallController::OnClickedNumberTwo()
{
	if (testGMB)
		testGMB->NumberTwo();
}

void AGolfBallController::OnClickedNumberThree()
{
	if (testGMB)
		testGMB->NumberThree();
}

void AGolfBallController::OnClickedNumberFour()
{
	if (testGMB)
		testGMB->NumberFour();
}

void AGolfBallController::OnClickedMoveForward(float AxisValue)
{
	auto CurrentPawn = (AGolfBall*)this->GetWorld()->GetFirstPlayerController()->GetPawn();
	if (CurrentPawn)
		CurrentPawn->MoveForward(AxisValue);
}

void AGolfBallController::OnClickedTurnRight(float AxisValue)
{
	auto CurrentPawn = (AGolfBall*)this->GetWorld()->GetFirstPlayerController()->GetPawn();
	if (CurrentPawn)
		CurrentPawn->TurnRight(AxisValue);
}

void AGolfBallController::OnClickedKeyboardC()
{
	auto CurrentPawn = (AGolfBall*)this->GetWorld()->GetFirstPlayerController()->GetPawn();
	if (CurrentPawn)
		CurrentPawn->Jump();
}

void AGolfBallController::OnMouseWheelDown()
{
	auto CurrentPawn = (AGolfBall*)this->GetWorld()->GetFirstPlayerController()->GetPawn();
	if (CurrentPawn)
		CurrentPawn->CameraZoomOut();
}

void AGolfBallController::OnMouseWheelUp()
{
	auto CurrentPawn = (AGolfBall*)this->GetWorld()->GetFirstPlayerController()->GetPawn();
	if (CurrentPawn)
		CurrentPawn->CameraZoomIn();
}
