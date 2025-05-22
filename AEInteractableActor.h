// (c) 2024 Adam's Embrace Team

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AEInteractableActor.generated.h"

/**
 * A Base Class to implement objects that the player can interact with.
 */
UCLASS(Blueprintable)
class AEINTERACTION_API AAEInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:
	AAEInteractableActor();

protected:
	/** Whether the actor can be interacted with or not. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInteractable = true;
	
	/** Whether the actor can be interacted with only once or many times. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsSingleUse = false;
	
	/**
	 * The time it takes to interact with the actor.
	 * 0 is the default.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractionTime = 0;

	/** The text to be prompted to the player when they look at the actor. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText InteractionPromptText = FText::FromString("'E' To Interact");

	/**
	 * Callback function for when an interaction first begins.
	 * Can be implemented in C++ or Blueprint.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnInteractionStarted();
	
	/**
	 * Callback function for when an interaction is canceled.
	 * Can be implemented in C++ or Blueprint.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnInteractionCanceled();
	
	/**
	 * Callback function for when an interaction is successfully finished.
	 * Can be implemented in C++ or Blueprint.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnInteractionFinished();

	/**
	 * Callback function for when progress is made on an interaction.
	 * Called every frame.
	 * Can be implemented in C++ or Blueprint.
	 * @param Progress A float from 0 to 1 representing the 'time' of the progress.
	 * 0 for 0% progress.
	 * 1 for 100% progress.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnInteractionProgressed(float Progress);

private:
	FTimerHandle InteractionTimer;
	bool bIsInProgress = false;

	void FinishInteraction();
	
public:	
	virtual void Tick(float DeltaTime) override;

	/**
	 * Interact with this actor.
	 * @see OnInteractionStarted()
	 * @see OnInteractionProgressed()
	 * @see OnInteractionFinished()
	 */
	void InteractWith();

	/**
	 * Cancel the actor's interaction.
	 * @see OnInteractionCanceled()
	 */
	void CancelInteraction();

	/** @returns The actor's interaction prompt. */
	const FText GetInteractionPromptText() const;

	/**
	 * @returns True if the actor is Interactable and is not being interacted with.
	 * False if the actor is not Interactable or is already being interacted with.
	 */
	const bool CanBeInteractedWith() const;

	/** @returns True if the actor is being interacted with. False otherwise. */
	const bool IsInteractionInProgress() const;

	/**
	 * @return A float from 0 to 1 representing the 'time' of the interaction.
	 * 0 if the interaction is 0% complete.
	 * 1 if the interaction is 100% complete.
	 */
	const float GetInteractionProgress() const;
};
