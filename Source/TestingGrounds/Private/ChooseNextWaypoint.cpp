// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// get the patrol points
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrollingComponent = ControlledPawn->FindComponentByClass<UPatrollingComponent>();

	if (!ensure(PatrollingComponent)) return EBTNodeResult::Failed;
	auto PatrolPoints = PatrollingComponent->GetPatrolPoints();
	if (PatrolPoints.Num() < 1) return EBTNodeResult::Failed;

	// set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle index
	auto NewIndex = (Index +  1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);

	return EBTNodeResult::Succeeded;
}