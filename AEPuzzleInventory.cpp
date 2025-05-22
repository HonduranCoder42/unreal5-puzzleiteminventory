// (c) 2024 Adam's Embrace Team


#include "AEPuzzleInventory.h"

#include "AEPuzzleDataAsset.h"

UAEPuzzleInventory::UAEPuzzleInventory()
{
	PuzzleItemsMap = TMap<FName, UAEPuzzleDataAsset*>();
}

bool UAEPuzzleInventory::AddPuzzleItem(UAEPuzzleDataAsset* PuzzleItem)
{
	UE_LOG(LogTemp, Error, TEXT("Add Puzzle Item Called"));
	if(!PuzzleItem)
	{
		UE_LOG(LogTemp, Error, TEXT("Add Puzzle Item Called"));
		return false;
	}

	if(PuzzleItemsMap.Contains(PuzzleItem->GetName()))
	{
		return false;
	}
	PuzzleItemsMap.Add(PuzzleItem->GetName(), Cast<UAEPuzzleDataAsset>(PuzzleItem));
	return PuzzleItemsMap.Contains(PuzzleItem->GetName());
}

bool UAEPuzzleInventory::RemovePuzzleItem(UAEPuzzleDataAsset* PuzzleItem)
{
	if(!PuzzleItem)
	{
		return false;
	}

	if(!PuzzleItemsMap.Contains(PuzzleItem->GetName()))
	{
		return false;
	}

	PuzzleItemsMap.Remove(PuzzleItem->GetName());
	return !PuzzleItemsMap.Contains(PuzzleItem->GetName());
}


bool UAEPuzzleInventory::HasPuzzleItem(UAEPuzzleDataAsset* PuzzleItem) const
{
	if(!PuzzleItem)
	{
		return false;
	}

	return PuzzleItemsMap.Contains(PuzzleItem->GetName());
}

TArray<UAEPuzzleDataAsset*> UAEPuzzleInventory::GetPuzzleItems()
{
	TArray<UAEPuzzleDataAsset*, FDefaultAllocator> ReturnArray = TArray<UAEPuzzleDataAsset*, FDefaultAllocator>();

	for(auto Elem : PuzzleItemsMap)
	{
		ReturnArray.Add(Elem.Value);
	}

	return ReturnArray;
}

int UAEPuzzleInventory::GetNumPuzzleItems() const
{
	return PuzzleItemsMap.Num();
}

void UAEPuzzleInventory::PrintPuzzleItems()
{
	UE_LOG(LogTemp, Warning, TEXT("PUZZLE ITEMS -> {"))
	for(auto& Elem : PuzzleItemsMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("\t%s"), *(Elem.Value->GetName().ToString()));
	}
	UE_LOG(LogTemp, Warning, TEXT("}"));
}


