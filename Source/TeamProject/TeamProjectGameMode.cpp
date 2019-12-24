// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TeamProjectGameMode.h"
#include "TeamProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"


ATeamProjectGameMode::ATeamProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/PizzaC.PizzaC_C"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	

}


