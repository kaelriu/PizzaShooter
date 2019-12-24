// Fill out your copyright notice in the Description page of Project Settings.

#include "PSState.h"

APSState::APSState()
{
	PizzaScore = 0;
}

void APSState::AddPizzaScore()
{
	PizzaScore++;

	OnPlayerScoreChanged.Broadcast();
}
