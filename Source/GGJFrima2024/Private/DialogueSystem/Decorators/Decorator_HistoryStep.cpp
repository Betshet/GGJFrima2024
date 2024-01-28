// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueSystem/Decorators/Decorator_HistoryStep.h"

#include "Helpers/MounteaDialogueSystemBFC.h"

void UDecorator_HistoryStep::InitializeDecorator_Implementation(UWorld* World, const TScriptInterface<IMounteaDialogueParticipantInterface>& OwningParticipant)
{
	Super::InitializeDecorator_Implementation(World, OwningParticipant);

	if (World)
	{
		Manager = UMounteaDialogueSystemBFC::GetDialogueManager(GetOwningWorld());
	}
}

void UDecorator_HistoryStep::CleanupDecorator_Implementation()
{
	Super::CleanupDecorator_Implementation();

	Context = nullptr;
	Manager = nullptr;
}

bool UDecorator_HistoryStep::ValidateDecorator_Implementation(TArray<FText>& ValidationMessages)
{
	bool bSatisfied = Super::EvaluateDecorator_Implementation();
	
	return bSatisfied;
}

void UDecorator_HistoryStep::ExecuteDecorator_Implementation()
{
	Super::ExecuteDecorator_Implementation();

	// Let's return BP Updatable Context rather than Raw
	if (!Context)
	{
		Context = Manager->GetDialogueContext();
	}
}