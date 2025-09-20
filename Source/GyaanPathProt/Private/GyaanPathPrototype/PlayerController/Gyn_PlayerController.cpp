// Fill out your copyright notice in the Description page of Project Settings.


#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GyaanPathPrototype/Components/Gyn_QuestionComponent.h"
#include "GyaanPathPrototype/Hud/Cursor/Gyn_WorldCursor.h"
#include "Kismet/GameplayStatics.h"


AGyn_PlayerController::AGyn_PlayerController()
{
	//initialize it to some value in the constructor
   TraceLength=500.f;
	//because trace is done every trick
	PrimaryActorTick.bCanEverTick = true;
	TraceChannel=ECC_GameTraceChannel1;
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
	//get the Question Component from the blueprint of playerController
	QuestionComponent=FindComponentByClass<UGyn_QuestionComponent>();
	if (!QuestionComponent.IsValid()) 
	{
		UE_LOG(LogTemp,Log,TEXT("The question Component is Invalid"));
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

void AGyn_PlayerController::createCursor()
{
	//as we don't want the Sever Player Controller To take Control
	if (!IsLocalPlayerController()) return;
	TObjectPtr<UGyn_WorldCursor> Cursor=CreateWidget<UGyn_WorldCursor>(this,CursorClass);
	if (!IsValid(Cursor)) return;
	Cursor->AddToViewport();
	
}

void AGyn_PlayerController::TraceForObjects()
{
	if (!IsLocalPlayerController()) return;
	if (!IsValid(GetWorld()) || !IsValid(GetWorld()->GetGameViewport())) return;
	FVector2D ViewportSize;
	GetWorld()->GetGameViewport()->GetViewportSize(ViewportSize);
	//to get the world Cursor u need the screens midpoint as the world cursor is in the middle of the screen
	FVector2D ViewportCenter=ViewportSize/2.f;
	FVector Direction;
	FVector TraceStart;
	//deproject from screen to world to get coordinates of the world
	//remember if & symbol comes then it is giving out referencing so it is taking viewport center and giving out position and Direction.
	if (UGameplayStatics::DeprojectScreenToWorld(this,ViewportCenter, TraceStart,Direction))
	{
		//have a hit result struct to get the output of trace
		FHitResult HitResult;
		//trace end
		FVector TraceEnd=TraceStart+Direction*TraceLength;
		//if this is true then only trace
		//to take ur custom collision channnel take l1
		GetWorld()->LineTraceSingleByChannel(HitResult,TraceStart,TraceEnd,TraceChannel);
		//take a weak pointer of  AActor to denote the actor changing
		LastActor=CurrentActor;
		//so ur going to get the actor
		CurrentActor=HitResult.GetActor();
          if (!LastActor.IsValid() && !CurrentActor.IsValid()) return;
		if (LastActor==CurrentActor) return;

		if (LastActor.IsValid())
		{
			UE_LOG(LogTemp,Log,TEXT("	Now Not Tracing Any Item"));
		}

		if (CurrentActor.IsValid())
		{
			
			OpenTheQuestion();
			
		}
	}
	
}

void AGyn_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TraceForObjects();
}

void AGyn_PlayerController::CloseTheQuestion()
{
	if (!QuestionComponent.IsValid()) return;
	QuestionComponent->closeQuestion();
}

void AGyn_PlayerController::OpenTheQuestion()
{
	if (!QuestionComponent.IsValid()) return;
	QuestionComponent->OpenQuestion();
}






