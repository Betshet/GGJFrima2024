// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MounteaDialogueManager.h" 
#include "Helpers/MounteaDialogueGraphHelpers.h"
#include "MyDialogueManager.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GGJFRIMA2024_API UMyDialogueManager : public UMounteaDialogueManager 
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NextDialogue()
	{
		if (!DialogueContext)
		{
			LOG_ERROR(TEXT("[NextDialogue] Missing Dialogue Context. Cannot continue dialogue."));
			return;
		}
		
		OnNextDialogueRowDataRequested.Broadcast(DialogueContext);
	}
};
