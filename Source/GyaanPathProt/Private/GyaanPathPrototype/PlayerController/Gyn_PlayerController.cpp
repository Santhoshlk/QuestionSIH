// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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


