// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISenseConfig_Hearing.h"

AEnemyAIController::AEnemyAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	HearingConfig = CreateDefaultSubobject < UAISenseConfig_Hearing>(TEXT("HearingConfig"));

	SightConfig->SightRadius = 3000.f;
	SightConfig->LoseSightRadius = 3500.f;

	HearingConfig->HearingRange = 3000.f;

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->ConfigureSense(*HearingConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AEnemy* Enemy = Cast<AEnemy>(InPawn);
	if(Enemy)
	{
		// Do something!
	}
}
