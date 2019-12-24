// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PizzaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API APizzaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	APizzaPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;
	
};
