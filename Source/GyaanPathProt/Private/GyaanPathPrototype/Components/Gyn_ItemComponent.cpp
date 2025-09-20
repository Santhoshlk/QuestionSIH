// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/Components/Gyn_ItemComponent.h"

UGyn_ItemComponent::UGyn_ItemComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

	
}

FName UGyn_ItemComponent::getQuestion()
{
	return QuestionName;
}

void UGyn_ItemComponent::setQuestion(FName QName)
{
	QuestionName=QName;
}


void UGyn_ItemComponent::BeginPlay()
{
	Super::BeginPlay();
}



