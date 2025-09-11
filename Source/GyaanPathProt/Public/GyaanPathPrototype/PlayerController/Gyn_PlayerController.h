// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Gyn_PlayerController.generated.h"

/**
 * 
 */
class UInputAction;
class UInputMappingContext;
UCLASS()

class GYAANPATHPROT_API AGyn_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
//add the required things u need to  make the input action binding
 AGyn_PlayerController();
 
 virtual void SetupInputComponent() override;

	void PrimaryActionFunction();
protected:

 virtual void BeginPlay() override;

private:
	//the primary Actions input Action and To make Everything Work Input Mapping Context
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> PrimaryAction;
	
	UPROPERTY(EditAnywhere,Category="Input")
    TArray<TObjectPtr<UInputMappingContext>> PlayerInputMappingContext;
    
};
