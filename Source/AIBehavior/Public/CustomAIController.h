// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CustomAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API ACustomAIController : public AAIController
{
	GENERATED_BODY()

public:
	ACustomAIController();

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	class UBehaviorTreeComponent* BTC;

	UPROPERTY()
	UBlackboardComponent* BBC;

	FBlackboard::FKey TargetActor;
	
};
