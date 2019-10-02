// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move Barrel the right amount this frame
	//Given max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
