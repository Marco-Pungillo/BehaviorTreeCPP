// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetPointOnPath.h"
#include "AIController.h"
#include "CustomAIPawn.h"
#include "SmartPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTTask_GetPointOnPath::UBTTask_GetPointOnPath()
{
	bCreateNodeInstance = true;
	NodeName = "Get Next Point on Path";
}

EBTNodeResult::Type UBTTask_GetPointOnPath::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	UBlackboardComponent* MyBlackboard = OwnerComponent.GetBlackboardComponent();
	AAIController* MyController = OwnerComponent.GetAIOwner();
	if (!MyBlackboard || !MyController)
	{
		return EBTNodeResult::Failed;
	}


	ACustomAIPawn* ControlledPawn = Cast<ACustomAIPawn>(MyController->GetPawn());
	if (ControlledPawn)
	{
		/*FVector NextTargetPoint = ControlledPawn->PawnPath->GetSplinePointAtIndex(PointIndex);
		int32 MaxPointsNum = ControlledPawn->PawnPath->SplineComponent->*/		
		TArray<FVector> PatrolPoints = ControlledPawn->PawnPath->GetSplinePoints();		
		MyBlackboard->SetValue<UBlackboardKeyType_Vector>(FName("TargetPatrolLocation"), PatrolPoints[PointIndex]);
		if (PointIndex < PatrolPoints.Num())
		{
			PointIndex++;
		}
		else
		{
			PointIndex = 0;
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
