// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Patrol.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_Patrol::UBTTask_Patrol()
{

}

EBTNodeResult::Type UBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) 
{
	AAIController* AIController = OwnerComponent.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	
	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BBC = OwnerComponent.GetBlackboardComponent();
	if (!BBC) 
	{
		return EBTNodeResult::Failed;
	}

	FVector PatrolLocation = BBC->GetValueAsVector("TargetPatrolLocation");

	// Method 1
	AIController->MoveToLocation(PatrolLocation);

	// Method 2
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavSys)
	{
		AIController->MoveToLocation(PatrolLocation);
		return EBTNodeResult::InProgress;
	}
	return EBTNodeResult::Failed;
}

void UBTTask_Patrol::TickTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaTime)
{
	Super::TickTask(OwnerComponent, NodeMemory, DeltaTime);

	AAIController* AIController = OwnerComponent.GetAIOwner();
	if (!AIController)
	{
		FinishLatentTask(OwnerComponent, EBTNodeResult::Failed);
	}

	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		FinishLatentTask(OwnerComponent, EBTNodeResult::Failed);
	}
	
		
	UBlackboardComponent* BBC = OwnerComponent.GetBlackboardComponent();
	if (!BBC) 
	{
		return FinishLatentTask(OwnerComponent, EBTNodeResult::Failed);
	}

	FVector PatrolLocation = BBC->GetValueAsVector("TargetPatrolLocation");

	if (hasReachedTarget(ControlledPawn, PatrolLocation, 100))
	{
		FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
	}

}

bool UBTTask_Patrol::hasReachedTarget(const APawn* ControlledPawn, const FVector& TargetLocation, float AcceptanceRadius)
{
	FVector ControlledPawnLocation = ControlledPawn->GetActorLocation();
	return FVector::Distance(ControlledPawnLocation, TargetLocation) < AcceptanceRadius;
}


