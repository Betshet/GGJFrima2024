// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueSystem/Decorators/Decorator_NeedItem.h"

#include "Helpers/MounteaDialogueSystemBFC.h"

void UDecorator_NeedItem::InitializeDecorator_Implementation(UWorld* World, const TScriptInterface<IMounteaDialogueParticipantInterface>& OwningParticipant)
{
	Super::InitializeDecorator_Implementation(World, OwningParticipant);

	if (World)
	{
		Manager = UMounteaDialogueSystemBFC::GetDialogueManager(GetOwningWorld());
	}
}

void UDecorator_NeedItem::CleanupDecorator_Implementation()
{
	Super::CleanupDecorator_Implementation();

	Context = nullptr;
	Manager = nullptr;
}

bool UDecorator_NeedItem::ValidateDecorator_Implementation(TArray<FText>& ValidationMessages)
{
	bool bSatisfied = Super::EvaluateDecorator_Implementation();
	
	return bSatisfied;
}

void UDecorator_NeedItem::ExecuteDecorator_Implementation()
{
	Super::ExecuteDecorator_Implementation();

	// Let's return BP Updatable Context rather than Raw
	if (!Context)
	{
		Context = Manager->GetDialogueContext();
	}
}
