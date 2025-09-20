// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gyn_ItemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class GYAANPATHPROT_API UGyn_ItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UGyn_ItemComponent();
	// add the public getter and setter functions
	FName getQuestion();

	void setQuestion(FName QName);

protected:

	virtual void BeginPlay() override;

private:
	//add the variable of FString message which we can set in blueprints to give the question
	UPROPERTY(EditAnywhere,Category="Question")
	FName QuestionName;
	
	
};
