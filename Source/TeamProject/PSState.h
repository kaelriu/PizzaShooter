// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PSState.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnPlayerStateChangeDelegate);

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API APSState : public APlayerState
{
	GENERATED_BODY()

public:

	APSState();

	UFUNCTION(BlueprintCallable)
	void AddPizzaScore();

	UFUNCTION(BlueprintCallable)
	int32 GetPizzaScore() { return PizzaScore; }

	FOnPlayerStateChangeDelegate OnPlayerScoreChanged;

protected:

	UPROPERTY(Transient) int32 PizzaScore;
	
};
