// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAIPawn.h"

// Sets default values
ACustomAIPawn::ACustomAIPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomAIPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomAIPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomAIPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

