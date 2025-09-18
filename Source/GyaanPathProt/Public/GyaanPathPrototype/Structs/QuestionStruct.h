
#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestionStruct.generated.h"

USTRUCT(BlueprintType)
struct FQuestionRow:public FTableRowBase
{
	GENERATED_BODY();
public:
	//create the required things for the question
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString Question;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString AOption;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString BOption;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString COption;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString DOption;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 QuestionIndex;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 AnswerIndex;
};