#include "Core/MainPlayerState.h"
#include "Net/UnrealNetwork.h"

void AMainPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerState, PlayerScore);
}

void AMainPlayerState::AddScore(int32 Amount)
{
	if (!HasAuthority())
		return;

	PlayerScore += Amount;
	OnRep_PlayerScore();
}

void AMainPlayerState::OnRep_PlayerScore()
{
	UE_LOG(LogTemp, Log, TEXT("[%s] Player %s score updated: %d"), HasAuthority() ? TEXT("Server") : TEXT("Client"), *GetPlayerName(), PlayerScore);
}