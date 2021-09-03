// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pakmania3DGameMode.h"
#include "Pakmania3DCharacter.h"
#include "UObject/ConstructorHelpers.h"

APakmania3DGameMode::APakmania3DGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
