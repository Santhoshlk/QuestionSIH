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
class UGyn_WorldCursor;
UCLASS()

class GYAANPATHPROT_API AGyn_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
//add the required things u need to  make the input action binding
 AGyn_PlayerController();
 
 virtual void SetupInputComponent() override;

	void PrimaryActionFunction();

	//generally understand that to create the widget we use a function nd then set it for begin play
	void createCursor();

	void TraceforObjects();

	virtual void Tick(float DeltaTime) override;
protected:

 virtual void BeginPlay() override;

private:
	//the primary Actions input Action and To make Everything Work Input Mapping Context
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> PrimaryAction;

	//because we need to set the old input mapping contexts to work otherwise the character will not move when we override with playercontroller
	UPROPERTY(EditAnywhere,Category="Input")
    TArray<TObjectPtr<UInputMappingContext>> PlayerInputMappingContext;

	//Create the TSubClass of the widget
	// for the dynamic creation of the cursor widget
	UPROPERTY(EditAnywhere,Category="Input")
	TSubclassOf<UGyn_WorldCursor> CursorClass;

	UPROPERTY(EditAnywhere,Category="Input")
	float TraceLength;

	TWeakObjectPtr<AActor> LastActor;
	TWeakObjectPtr<AActor> CurrentActor;

	UPROPERTY(EditAnywhere,Category="Input")
	TEnumAsByte<ECollisionChannel> TraceChannel;	
};
