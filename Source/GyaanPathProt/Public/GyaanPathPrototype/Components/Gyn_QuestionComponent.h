// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gyn_QuestionComponent.generated.h"

class UGyn_QuestionBase;
// write blueprintable so that u can make a bp of it and add it as a component in unreal editor to the player Controller
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class GYAANPATHPROT_API UGyn_QuestionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UGyn_QuestionComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void closeQuestion();
	void OpenQuestion();
protected:
	
	virtual void BeginPlay() override;

private:
     void CreateQuestion();
	
   //to use create widget we need the owner u can get the owner by casting to get owner
	   TWeakObjectPtr<APlayerController> Owner;
	
	//create a TSubClass Of the question component because that way we can create a widget that's owned by the player controller
	UPROPERTY(EditDefaultsOnly,Category="Components")
	TSubclassOf<UGyn_QuestionBase> QuestionClass;

	//to have a pointer to the object
	// just have UPROPERTY To avoid Garbage Collection
	UPROPERTY()
	TObjectPtr<UGyn_QuestionBase> Question;

	UPROPERTY(meta=(AllowPrivateAccess="true"),BlueprintReadOnly,Category="Question")
	bool IsTheQuestionOpen;
	
 protected:
  template <class T>
	T* GetOwningPlayerController()
	{
  	  static_assert(TPointerIsConvertibleFromTo<T,APlayerController>::Value,"This pointer will be allowed to cast to a child or The class of APlayerController");
  	   return Cast<T>(GetOwner());
	}
};
