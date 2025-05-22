// (c) 2024 Adam's Embrace Team


#include "AEPuzzleDataAsset.h"

UAEPuzzleDataAsset::UAEPuzzleDataAsset()
{
	
}

void UAEPuzzleDataAsset::OnPickup() const
{
	UE_LOG(LogTemp, Warning, TEXT("PICKED UP PUZZLE ITEM"));

}

FName UAEPuzzleDataAsset::GetName() const
{
	return Name;
}