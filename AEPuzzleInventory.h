// (c) 2024 Adam's Embrace Team

#pragma once

#include "CoreMinimal.h"
#include "AEPuzzleInventory.generated.h"

class UAEPuzzleDataAsset;

/**
 * A class to contain puzzle items collected by the player.
 */
UCLASS()
class AEPUZZLES_API UAEPuzzleInventory : public UObject
{
	GENERATED_BODY()

public:
	UAEPuzzleInventory();

	/**
	 * Add a puzzle item to the inventory.
	 * @param PuzzleItem The puzzle to be added to PuzzleInventory.
	 * @return True if the puzzle item was successfully added.
	 * False if the puzzle item could not be added.
	 */
	UFUNCTION(BlueprintCallable)
	bool AddPuzzleItem(UAEPuzzleDataAsset* PuzzleItem);

	/**
	 * Removes a puzzle item from the inventory
	 * @param PuzzleItem The puzzle item to be removed from PuzzleInventory
	 * @return True if the puzzle item was successfully removed
	 * False if the puzzle item could not be removed
	 */
	UFUNCTION(BlueprintCallable)
	bool RemovePuzzleItem(UAEPuzzleDataAsset* PuzzleItem);

	/**
	 * Check if a puzzle item is contained in the inventory.
	 * @param PuzzleItem The puzzle item to be checked.
	 * @return True if the puzzle item is within the inventory.
	 * False if the puzzle item is not within the inventory.
	 */
	UFUNCTION(BlueprintPure)
	bool HasPuzzleItem(UAEPuzzleDataAsset* PuzzleItem) const;

	/**
	 * Returns an array of PuzzleDataAssets with items contained in inventory.
	 * @return An array of puzzle items contained in inventory.
	 */
	UFUNCTION(BlueprintPure)
	TArray<UAEPuzzleDataAsset*> GetPuzzleItems();

	/** @return The total number of puzzle items in inventory */
	UFUNCTION(BlueprintPure)
	int GetNumPuzzleItems() const;

	/** A debug function to print the contents of the inventory to the Log. */
	void PrintPuzzleItems();

private:
	TMap<FName, UAEPuzzleDataAsset*> PuzzleItemsMap;
};
