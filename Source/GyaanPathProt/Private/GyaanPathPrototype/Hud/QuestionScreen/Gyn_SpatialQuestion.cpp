// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/Hud/QuestionScreen/Gyn_SpatialQuestion.h"
#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"
#include "Components/Button.h"

void UGyn_SpatialQuestion::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	// now bind The buttons To The On Clicked Functions
	OptionA->OnClicked.AddDynamic(this,&UGyn_SpatialQuestion::OptionAClicked);
	OptionB->OnClicked.AddDynamic(this,&UGyn_SpatialQuestion::OptionBClicked);
	OptionC->OnClicked.AddDynamic(this,&UGyn_SpatialQuestion::OptionCClicked);
	OptionD->OnClicked.AddDynamic(this,&UGyn_SpatialQuestion::OptionDClicked);
	getPlayerController();
}

void UGyn_SpatialQuestion::OptionAClicked()
{
	UE_LOG(LogTemp,Log,TEXT("Option A is clicked"))
}

void UGyn_SpatialQuestion::OptionBClicked()
{
	PC->CloseTheQuestion();
}

void UGyn_SpatialQuestion::OptionCClicked()
{
	UE_LOG(LogTemp,Log,TEXT("Option C is clicked"))
}

void UGyn_SpatialQuestion::OptionDClicked()
{
	UE_LOG(LogTemp,Log,TEXT("Option D is clicked"))
}

void UGyn_SpatialQuestion::getPlayerController()
{
	PC=Cast<AGyn_PlayerController>(GetOwningPlayer());
	if (!PC.IsValid()) return;
}
