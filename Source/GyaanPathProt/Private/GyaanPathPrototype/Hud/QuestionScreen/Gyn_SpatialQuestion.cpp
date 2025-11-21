#include "GyaanPathPrototype/Hud/QuestionScreen/Gyn_SpatialQuestion.h"
#include "GyaanPathPrototype/PlayerController/Gyn_PlayerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "QuestionStruct.h"
#include "GyaanPathProtCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGyn_SpatialQuestion::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    // ✅ Cache player controller ONCE here
    PC = Cast<AGyn_PlayerController>(GetOwningPlayer());

    // ✅ Bind buttons
    if (OptionA) OptionA->OnClicked.AddDynamic(this, &UGyn_SpatialQuestion::OptionAClicked);
    if (OptionB) OptionB->OnClicked.AddDynamic(this, &UGyn_SpatialQuestion::OptionBClicked);
    if (OptionC) OptionC->OnClicked.AddDynamic(this, &UGyn_SpatialQuestion::OptionCClicked);
    if (OptionD) OptionD->OnClicked.AddDynamic(this, &UGyn_SpatialQuestion::OptionDClicked);

    //we need to cast to our character
    MyCharacter = Cast<AGyaanPathProtCharacter>(GetOwningPlayerPawn());
    if (IsValid(MyCharacter))
    {
        Movement=MyCharacter->GetCharacterMovement();
    }
}

void UGyn_SpatialQuestion::NativeConstruct()
{
    Super::NativeConstruct();

    if (!IsValid(QuestionDataTable)) return;
   
    Attribute=0;
    //  Get the question name from PlayerController
  
    // ✅ Look up the row in the datatable
    FQuestionRow* QuestionRow = QuestionDataTable->FindRow<FQuestionRow>(
        QuestionNane,
        FString(TEXT("Looking up Question Row"))
    );

    if (!QuestionRow) return;

    // ✅ Update UI texts
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

    Answer = QuestionRow->AnswerIndex;
}

void UGyn_SpatialQuestion::OptionAClicked()
{
    if (Answer == 1 )
    {
        PC->CloseTheQuestion();
        Attribute+=10;
        if (GEngine)
        {
            FString Message = FString::Printf(TEXT("Attribute Value is %d"),Attribute);
            GEngine->AddOnScreenDebugMessage(0,5.f,FColor::Green,Message);
        }
        if (Movement)
        {
            Movement->MaxWalkSpeed+=150.f;
        }
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Green,TEXT("The Max Walking Speed has been Increased"));
        }
    }
}

void UGyn_SpatialQuestion::OptionBClicked()
{
    if (Answer == 2 && PC.IsValid())
    {
        
        PC->CloseTheQuestion();
        Attribute+=10;
        if (GEngine)
        {
            FString Message = FString::Printf(TEXT("Attribute Value is %d"),Attribute);
            GEngine->AddOnScreenDebugMessage(0,5.f,FColor::Green,Message);
        }
        if (Movement)
        {
            Movement->MaxWalkSpeed+=150.f;
        }
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Green,TEXT("The Max Walking Speed has been Increased"));
        }
    }
}

void UGyn_SpatialQuestion::OptionCClicked()
{
    if (Answer == 3 && PC.IsValid())
    {
        PC->CloseTheQuestion();
        Attribute+=10;
        if (GEngine)
        {
            FString Message = FString::Printf(TEXT("Attribute Value is %d"),Attribute);
            GEngine->AddOnScreenDebugMessage(0,5.f,FColor::Green,Message);
        }
    }
    if (Movement)
    {
        Movement->MaxWalkSpeed+=150.f;
    }
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Green,TEXT("The Max Walking Speed has been Increased"));
    }
}

void UGyn_SpatialQuestion::OptionDClicked()
{
    if (Answer == 4 && PC.IsValid()) 
    {
        PC->CloseTheQuestion();
        Attribute+=10;
        if (GEngine)
        {
            FString Message = FString::Printf(TEXT("Attribute Value is %d"),Attribute);
            GEngine->AddOnScreenDebugMessage(0,5.f,FColor::Green,Message);
        }
    }
    if (Movement)
    {
        Movement->MaxWalkSpeed+=150.f;
    }
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(1,1.f,FColor::Green,TEXT("The Max Walking Speed has been Increased"));
    }
}

void UGyn_SpatialQuestion::Close()
{
   if (PC.IsValid())
   {
       PC->CloseTheQuestion();
   }
}
