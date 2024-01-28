// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorators/MounteaDialogueDecoratorBase.h"

#include "Decorator_Trigger.generated.h"

class UMounteaDialogueContext;
class IMounteaDialogueManagerInterface;
/**
 * 
 */
UCLASS( BlueprintType, EditInlineNew, ClassGroup=("Dialogue"), AutoExpandCategories=("Dialogue"), DisplayName="Trigger on finish")
class GGJFRIMA2024_API UDecorator_Trigger : public UMounteaDialogueDecoratorBase
{
	GENERATED_BODY()
public:
	virtual void InitializeDecorator_Implementation(UWorld* World, const TScriptInterface<IMounteaDialogueParticipantInterface>& OwningParticipant) override;
	virtual void CleanupDecorator_Implementation() override;
	virtual bool ValidateDecorator_Implementation(TArray<FText>& ValidationMessages) override;
	virtual void ExecuteDecorator_Implementation() override;
	
	virtual  FString GetDecoratorDocumentationLink_Implementation() const override
	{
		return TEXT("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
	}

protected:
	UMounteaDialogueContext* GetContext() const
	{
		return Context;
	}
	
	TScriptInterface<IMounteaDialogueManagerInterface> GetManager() const
	{
		return Manager;
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString TriggerName;
	
private:
	UMounteaDialogueContext* Context = nullptr;
	TScriptInterface<IMounteaDialogueManagerInterface> Manager = nullptr;
};
