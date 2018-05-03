// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrateManager.generated.h"

UCLASS()
class PROJECT_BOMBGAME_API ACrateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrateManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Create a list of unique random numbers within range
	//If size is bigger than rangem, return an empty list
	UFUNCTION(BlueprintCallable)
	TArray<int> GenerateListOfRandomNumbers(int numsToGenerate, int range);

	//Return a random number not found in the given list
	UFUNCTION(BlueprintCallable)
	int FillInRandomNumber(int range, TArray<int> values);
	
	//Reset the drop table back to it's initial state
	//(Can be changed in the C++ class)
	UFUNCTION(BlueprintCallable)
	void resetDropTable();

	UFUNCTION(BlueprintCallable)
	void initRandomSeed();

	//Get a random element from the list and remove it from the list
	UFUNCTION(BlueprintCallable)
	int dropItem();

	UPROPERTY()
	TArray<int> DropTable;
};
