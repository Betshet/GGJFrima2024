// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorators/MounteaDialogueDecoratorBase.h"
#include "Decorator_HistoryStep.generated.h"

class UMounteaDialogueContext;
class IMounteaDialogueManagerInterface;
/**
 * 
 */
UCLASS( BlueprintType, EditInlineNew, ClassGroup=("Dialogue"), AutoExpandCategories=("Dialogue"), DisplayName="Need History Step to Activate")
class GGJFRIMA2024_API UDecorator_HistoryStep : public UMounteaDialogueDecoratorBase
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
	FString StepName;
	
private:
	UMounteaDialogueContext* Context = nullptr;
	TScriptInterface<IMounteaDialogueManagerInterface> Manager = nullptr;
};
