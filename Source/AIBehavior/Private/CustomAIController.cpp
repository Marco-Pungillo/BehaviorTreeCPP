// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CustomAIPawn.h"

ACustomAIController::ACustomAIController()
{
	BBC = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BTC = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

void ACustomAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ACustomAIPawn* ControlledPawn = Cast<ACustomAIPawn>(InPawn);
	if (ControlledPawn && ControlledPawn->BehaviorTreeAsset)
	{
		BBC->InitializeBlackboard(*ControlledPawn->BehaviorTreeAsset->BlackboardAsset);

		TargetActor = BBC->GetKeyID(FName("TargetActor"));

		BTC->StartTree(*ControlledPawn->BehaviorTreeAsset);
	}
}
