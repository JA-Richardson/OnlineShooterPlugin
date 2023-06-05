// Copyright Epic Games, Inc. All Rights Reserved.

#include "OnlineShooterGameMode.h"
#include "OnlineShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOnlineShooterGameMode::AOnlineShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
