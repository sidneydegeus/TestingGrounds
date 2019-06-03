// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	return EBTNodeResult::Succeeded;
}