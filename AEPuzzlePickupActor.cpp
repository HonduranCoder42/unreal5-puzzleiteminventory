// (c) 2024 Adam's Embrace Team


#include "AEPuzzlePickupActor.h"

#include "AEPuzzleDataAsset.h"
#include "AEPuzzleInventory.h"
#include "Kismet/GameplayStatics.h"

void AAEPuzzlePickupActor::OnInteractionFinished_Implementation()
{
	UE_LOG(LogTemp, Error, TEXT("Interaction Finished Called!"));
	// AAEGameMode* GameMode = Cast<AAEGameMode>(UGameplayStatics::GetGameMode(this));
	// if(GameMode && PuzzleItem)
	// {
	TObjectPtr<UAEPuzzleInventory> PuzzleInventory = GetPuzzleInventory();
	if(PuzzleInventory)
	{
		UE_LOG(LogTemp, Error, TEXT("Puzzle Inventory Does Exist"));
		bool bWasAddedToInventory = PuzzleInventory->AddPuzzleItem(PuzzleItem);

		// Debug Printing -> Remove when Artifacts Menu is implemented
		GetPuzzleInventory()->PrintPuzzleItems();

		if(bWasAddedToInventory)
		{
			PuzzleItem->OnPickup();
			Destroy();
		}
	}
}


UAEPuzzleInventory* AAEPuzzlePickupActor::GetPuzzleInventory_Implementation() const
{
	UE_LOG(LogTemp, Error, TEXT("AEPuzzlePickupActor does not implement GetPuzzleInventory()!"));
	UE_LOG(LogTemp, Error, TEXT("Inherit from BP_AEPuzzlePickupActor instead!"));
	return nullptr;
}