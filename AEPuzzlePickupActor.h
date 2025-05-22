// (c) 2024 Adam's Embrace Team

#pragma once

#include "CoreMinimal.h"
#include "AEInteractableActor.h"
#include "AEPuzzlePickupActor.generated.h"

class UAEPuzzleInventory;
class UAEPuzzleDataAsset;
/**
 * 
 */
UCLASS()
class AAEPuzzlePickupActor : public AAEInteractableActor
{
	GENERATED_BODY()

protected:
	/** The puzzle item to be picked up by the player. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UAEPuzzleDataAsset> PuzzleItem;
	
	virtual void OnInteractionFinished_Implementation() override;
	
	UFUNCTION(BlueprintNativeEvent)
	UAEPuzzleInventory* GetPuzzleInventory() const;
};
