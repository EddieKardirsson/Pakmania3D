// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class PAKMANIA3D_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyAIController();

	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
	class UAISenseConfig_Hearing* HearingConfig;

protected:

	virtual void OnPossess(APawn* InPawn) override;

	
};
