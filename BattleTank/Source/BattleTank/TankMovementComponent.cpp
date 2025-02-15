// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTankTrackToSet, UTankTrack* RightTankTrackToSet)
{
	LeftTrack = LeftTankTrackToSet;
	RightTrack = RightTankTrackToSet;

	if (!LeftTankTrackToSet || !RightTankTrackToSet) { return; }
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to: %s"), *TankName, *MoveVelocityString)
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	//LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}