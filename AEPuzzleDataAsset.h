// (c) 2024 Adam's Embrace Team

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AEPuzzleDataAsset.generated.h"



/**
 * A Data Asset to hold information about puzzle items
 * the player can collect or interact with in the world.
 */
UCLASS()
class AEPUZZLES_API UAEPuzzleDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAEPuzzleDataAsset();
	
	UFUNCTION(BlueprintCallable)
	virtual void OnPickup() const;
	
	/** @return The puzzle item's name. */
	UFUNCTION(BlueprintCallable)
	FName GetName() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(DisplayThumbnail="true", DisplayName="Icon", AllowedClasses="/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", DisallowedClasses = "/Script/MediaAssets.MediaTexture"))
	TObjectPtr<UObject> ResourceObject;

};