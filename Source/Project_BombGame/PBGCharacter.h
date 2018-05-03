// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine.h"
#include "PBGCharacter.generated.h"

UCLASS()
class PROJECT_BOMBGAME_API APBGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APBGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Handles input for moving forward and backward
	UFUNCTION()
	void MoveForward(float value);

	//Handles input for mocing right and left
	UFUNCTION()
	void MoveRight(float value);

	//Handles jumping input
	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	//Change character's gravity
	UFUNCTION(BlueprintCallable)
	void ChangeGravity(float newGravity);
};
