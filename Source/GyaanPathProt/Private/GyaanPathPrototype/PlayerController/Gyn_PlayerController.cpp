// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GyaanPathPrototype/Hud/Cursor/Gyn_WorldCursor.h"

AGyn_PlayerController::AGyn_PlayerController()
{
  
}



void AGyn_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	//connect it to enhance InputLocalPlayerSubsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(Subsystem)) return;
	 for (TObjectPtr<UInputMappingContext> CurrentMappingContext: PlayerInputMappingContext)
	 {
		 Subsystem->AddMappingContext(CurrentMappingContext,0);
	 }
	//obviously our cursor is going to be created in the starting of the game
	createCursor();
}

void AGyn_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent*PlayerComponent=CastChecked<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(PlayerComponent)) return;
	PlayerComponent->BindAction(PrimaryAction,ETriggerEvent::Started,this,&AGyn_PlayerController::PrimaryActionFunction);
	
}

void AGyn_PlayerController::PrimaryActionFunction()
{
	UE_LOG(LogTemp,Log,TEXT("E pressed for PrimaryAction"));
}

void AGyn_PlayerController::createCursor()
{
	//as we don't want the Sever Player Controller To take Control
	if (!IsLocalPlayerController()) return;
	TObjectPtr<UGyn_WorldCursor> Cursor=CreateWidget<UGyn_WorldCursor>(this,CursorClass);
	if (!IsValid(Cursor)) return;
	Cursor->AddToViewport();
	
}


