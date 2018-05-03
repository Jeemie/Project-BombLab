// Fill out your copyright notice in the Description page of Project Settings.

#include "CrateManager.h"
#include "CrateSpawnpoint.h"
#include "Engine.h"
#include <ctime>


// Sets default values
ACrateManager::ACrateManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrateManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrateManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrateManager::initRandomSeed() {
	srand(time(NULL));
}

TArray<int> ACrateManager::GenerateListOfRandomNumbers(int numsToGenerate, int range) {
	TArray<int> values;

	if (numsToGenerate > range) {
		return values;
	}

	for (int i = 0; i < numsToGenerate; ) {
		int num = rand() % range;
		if (!values.Contains(num)) {
			values.Add(num);
			i++;
		}
	}
	return values;
}

int ACrateManager::FillInRandomNumber(int range, TArray<int> values) {
	//Check that entire range isn't already covered
	TArray<int> temp;
	//Generate all numbers within range
	for (int i = 0; i < range; i++) {
		temp.Add(i);
	}
	//Remove numbers already in list
	for (int i = 0; i < values.Num(); i++) {
		temp.Remove(*values.FindByKey(i));
		int j = *values.FindByKey(i);
	}
	//If no numbers left to generate, error value
	if (temp.Num() == 0) { return -1; }

	//Else, return one of the remaining numbers at random
	srand(time(0));
	int num = rand() % temp.Num();
	return *temp.FindByKey(num);
}

//Reset the drop table back to it's initial state
//(Can be changed in the C++ class)
void ACrateManager::resetDropTable() {
	//Count of items to add
	int nothing = 6;		//0
	int defusers = 3;		//1
	int health = 5;			//2
	int doublejump = 5;		//3
	int extratime = 8;		//4

	//Empty the table
	DropTable.Empty();

	//Add nothing
	for (int i = 0; i < nothing; i++) {
		DropTable.Add(0);
	}

	//Add defusers
	for (int i = 0; i < defusers; i++) {
		DropTable.Add(1);
	}

	//Add health
	for (int i = 0; i < health; i++) {
		DropTable.Add(2);
	}

	//Add doublejump
	for (int i = 0; i < doublejump; i++) {
		DropTable.Add(3);
	}

	//Add extratime
	for (int i = 0; i < extratime; i++) {
		DropTable.Add(4);
	}
}

//Get a random element from the list and remove it from the list
int ACrateManager::dropItem() {
	//If there's nothing to drop, return error value
	if (DropTable.Num() <= 0) { return -1; }

	//Get a random element from list
	int length = DropTable.Num();
	int num = (rand() % length);

	//Get which kind of item it was and remove ir from list
	int result = DropTable[num];
	DropTable.RemoveAt(num);
	//Return what kind of item it was
	return result;
}