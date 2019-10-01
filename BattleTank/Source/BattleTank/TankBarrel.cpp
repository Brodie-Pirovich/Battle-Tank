// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "GameFramework/Actor.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move Barrel the right amount this frame
	//Given max elevation speed, and the frame time
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), Time, RelativeSpeed)
}
