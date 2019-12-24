// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/GameState.h"
#include "TeamProjectGameState.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TEAMPROJECT_API ATeamProjectGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	ATeamProjectGameState();

	void PostInitializeComponents() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		TArray<AActor*> Group1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		TArray<AActor*> Group2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		TArray<AActor*> Group3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		TArray<AActor*> Group4;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		TArray<AActor*> Group5;

public:
	/*
	UFUNCTION(BlueprintType, Category = Score, BlueprintCallable)
		TArray<AActor*>  FindScoreZoneGroupName(FName groupname);
	*/
	
};
