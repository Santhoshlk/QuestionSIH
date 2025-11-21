// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gyn_QuestionBase.h"
#include "Gyn_SpatialQuestion.generated.h"

class UCharacterMovementComponent;
class AGyaanPathProtCharacter;
class UTextBlock;
class UButton;
class AGyn_PlayerController;
/**
 * 
 */
UCLASS()
class GYAANPATHPROT_API UGyn_SpatialQuestion : public UGyn_QuestionBase
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
	//TO use this u need a Macro of U function
	UFUNCTION()
	void OptionAClicked();
	UFUNCTION()
	void OptionBClicked();
	UFUNCTION()
	void OptionCClicked();
	UFUNCTION()
	void OptionDClicked();

   UFUNCTION(BlueprintCallable)
	void Close();
	
private:
	//First of all Make 1 Text
	//4 buttons
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OptionA;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OptionB;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OptionC;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OptionD;

	//CREATE all the required text so that we can bind them for the Blueprint
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> OptionAText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> OptionBText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> OptionCText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> OptionDText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> CurrentQuestion;

	
	TWeakObjectPtr<AGyn_PlayerController> PC;


	//create an object for the datatable
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UDataTable> QuestionDataTable;
	
	UPROPERTY(EditAnywhere,Category="Input")
	FName QuestionNane;
	int32 Answer;

	int32 Attribute;

	UPROPERTY()
	TObjectPtr<AGyaanPathProtCharacter> MyCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> Movement;
};
