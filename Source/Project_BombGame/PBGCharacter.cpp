// Fill out your copyright notice in the Description page of Project Settings.

#include "PBGCharacter.h"
#include "Engine.h"


// Sets default values
APBGCharacter::APBGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APBGCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->GravityScale = 2.5;
}

// Called every frame
void APBGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APBGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Set up movement bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &APBGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APBGCharacter::MoveRight);

	// Set up camera bindings.
	PlayerInputComponent->BindAxis("Turn", this, &APBGCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APBGCharacter::AddControllerPitchInput);

	// Set up "action" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APBGCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APBGCharacter::StopJump);
}

//Move character right and left
void APBGCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

//Move character forward and backward
void APBGCharacter::MoveForward(float Value) {
	//FInd out which way is "forward" and record that the player wants to move that way
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

//Handles jumping input
void APBGCharacter::StartJump() {
	bPressedJump = true;
}

void APBGCharacter::StopJump() {
	bPressedJump = false;
}

void APBGCharacter::ChangeGravity(float newGravity) {
	GetCharacterMovement()->GravityScale = newGravity;
}