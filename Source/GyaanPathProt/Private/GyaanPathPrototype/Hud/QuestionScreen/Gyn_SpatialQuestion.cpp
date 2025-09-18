// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/Hud/QuestionScreen/Gyn_SpatialQuestion.h"
#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "QuestionStruct.h"

void UGyn_SpatialQuestion::NativeConstruct()
{
	Super::NativeConstruct();

	//First check if the question table is valid
	if (IsValid(QuestionDataTable))
	{
		//u cannot create an object of the data type and sheet u can only look at them through a pointer
		//for find row give a FName from RowName and then ContextString it is just a debug helper
		FQuestionRow* QuestionRow=QuestionDataTable->FindRow<FQuestionRow>(FName(TEXT("Q1")),FString(TEXT("The Question Which we were searching is found")));
		if (QuestionRow)
		{
			if (IsValid(CurrentQuestion))
			{
				CurrentQuestion->SetText(FText::FromString(QuestionRow->Question));
			}
			if (IsValid(OptionAText))
			{
				OptionAText->SetText(FText::FromString(QuestionRow->AOption));
			}
			if (IsValid(OptionBText))
			{
				OptionBText->SetText(FText::FromString(QuestionRow->BOption));
			}
			if (IsValid(OptionCText))
			{
				OptionCText->SetText(FText::FromString(QuestionRow->COption));
			}
			if (IsValid(OptionDText))
			{
				OptionDText->SetText(FText::FromString(QuestionRow->DOption));
			}
			Answer=QuestionRow->AnswerIndex;
		}
	}
}

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
	if (Answer==1)
	{
		PC->CloseTheQuestion();
	}
}

void UGyn_SpatialQuestion::OptionBClicked()
{
	if (Answer==2)
	{
		PC->CloseTheQuestion();
	}
}

void UGyn_SpatialQuestion::OptionCClicked()
{
	if (Answer==3)
	{
		PC->CloseTheQuestion();
	}
}

void UGyn_SpatialQuestion::OptionDClicked()
{
	if (Answer==4)
	{
		PC->CloseTheQuestion();
	}
}

void UGyn_SpatialQuestion::getPlayerController()
{
	PC=Cast<AGyn_PlayerController>(GetOwningPlayer());
	if (!PC.IsValid()) return;
}
