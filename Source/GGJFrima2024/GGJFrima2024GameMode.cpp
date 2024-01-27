// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJFrima2024GameMode.h"
#include "GGJFrima2024Character.h"
#include "UObject/ConstructorHelpers.h"

AGGJFrima2024GameMode::AGGJFrima2024GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
