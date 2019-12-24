// Fill out your copyright notice in the Description page of Project Settings.

#include "TeamProjectGameState.h"

ATeamProjectGameState::ATeamProjectGameState()
{

}

void ATeamProjectGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("1"), Group1);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("2"), Group2);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("3"), Group3);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("4"), Group4);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("5"), Group5);
}
/*
TArray<AActor*> ATeamProjectGameState::FindScoreZoneGroupName(FName groupname)
{
	

	return TArray<AActor*>();
}
*/
