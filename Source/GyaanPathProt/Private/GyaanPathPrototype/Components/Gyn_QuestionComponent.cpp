


#include "GyaanPathPrototype/Components/Gyn_QuestionComponent.h"
#include "GyaanPathPrototype/Hud/QuestionScreen/Gyn_QuestionBase.h"


UGyn_QuestionComponent::UGyn_QuestionComponent()
{
	// u don't require these functions to be called every single frame
	PrimaryComponentTick.bCanEverTick = false;

	
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
}


void UGyn_QuestionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

