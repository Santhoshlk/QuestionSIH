


#include "GyaanPathPrototype/Components/Gyn_QuestionComponent.h"
#include "GyaanPathPrototype/Hud/QuestionScreen/Gyn_QuestionBase.h"


UGyn_QuestionComponent::UGyn_QuestionComponent()
{
	// u don't require these functions to be called every single frame
	PrimaryComponentTick.bCanEverTick = false;
    IsTheQuestionOpen=false;
	
}



void UGyn_QuestionComponent::BeginPlay()
{
	Super::BeginPlay();

	CreateQuestion();
}

void UGyn_QuestionComponent::CreateQuestion()
{
	//get the owner
	Owner=Cast<APlayerController>(GetOwner());
	if (!Owner.IsValid()) return;
	Question=CreateWidget<UGyn_QuestionBase>(Owner.Get(),QuestionClass);
	if (!IsValid(Question)) return;
	Question->AddToViewport();
	//as u make the object first set its visibility to collapsed
	Question->SetVisibility(ESlateVisibility::Collapsed);
}

void UGyn_QuestionComponent::closeQuestion()
{
	if (!IsValid(Question)) return;
	if (!Owner.IsValid()) return;
	if (!IsTheQuestionOpen) return;
	//next set the value of the bool
	IsTheQuestionOpen=false ;
	//set the visibility of the object
	Question->SetVisibility(ESlateVisibility::Collapsed);
	//next set the mouse to disappear
	//u can do that with a player controller and then using a struct to override every thing
	FInputModeGameAndUI Input;
	Owner->SetInputMode(Input);
	Owner->SetShowMouseCursor(false);
}

void UGyn_QuestionComponent::OpenQuestion()
{
	if (!IsValid(Question)) return;
	if (!Owner.IsValid()) return;
	if (IsTheQuestionOpen) return;
	//next set the value of the bool
	IsTheQuestionOpen=true;
	//set the visibility of the object
	Question->SetVisibility(ESlateVisibility::Visible);
	//next set the mouse to appear
	//u can do that with a player controller and then using a struct to override every thing
	FInputModeGameAndUI Input;
	Owner->SetInputMode(Input);
	Owner->SetShowMouseCursor(true);
	
}


void UGyn_QuestionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}