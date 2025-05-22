// (c) 2024 Adam's Embrace Team


#include "AEInteractableActor.h"

AAEInteractableActor::AAEInteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsInteractable = true;
	bIsSingleUse = false;
	InteractionTime = 0;
	InteractionPromptText = FText::FromString("'E' To Interact");
	bIsInProgress = false;
}

void AAEInteractableActor::OnInteractionStarted_Implementation()
{
}

void AAEInteractableActor::OnInteractionCanceled_Implementation()
{
}

void AAEInteractableActor::OnInteractionFinished_Implementation()
{
}

void AAEInteractableActor::OnInteractionProgressed_Implementation(float Progress)
{
}

void AAEInteractableActor::FinishInteraction()
{
	if(!bIsInProgress)
	{
		return;
	}
	
	bIsInProgress = false;
	if(bIsSingleUse)
	{
		bIsInteractable = false;
	}

	GetWorldTimerManager().ClearTimer(InteractionTimer);
	OnInteractionFinished();
}

void AAEInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsInProgress)
	{
		OnInteractionProgressed(GetInteractionProgress());
	}
}

void AAEInteractableActor::InteractWith()
{
	if(CanBeInteractedWith())
	{
		bIsInProgress = true;
		OnInteractionStarted();
		if(InteractionTime <= 0)
		{
			FinishInteraction();
			return;
		}
		
		GetWorldTimerManager().SetTimer(InteractionTimer, this, &AAEInteractableActor::FinishInteraction, InteractionTime);
	}
}

void AAEInteractableActor::CancelInteraction()
{
	if(bIsInProgress)
	{
		OnInteractionCanceled();
		bIsInProgress = false;
		GetWorldTimerManager().ClearTimer(InteractionTimer);
	}
}

const FText AAEInteractableActor::GetInteractionPromptText() const
{
	return InteractionPromptText;
}

const bool AAEInteractableActor::CanBeInteractedWith() const
{
	return bIsInteractable && !bIsInProgress;
}

const bool AAEInteractableActor::IsInteractionInProgress() const
{
	return bIsInProgress;
}

const float AAEInteractableActor::GetInteractionProgress() const
{
	if(!bIsInProgress)
	{
		return 0;
	}

	return (GetWorldTimerManager().GetTimerElapsed(InteractionTimer) / InteractionTime);
}
