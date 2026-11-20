#include "Core/MainPlayerController.h"
#include "Core/MainPlayerState.h"

void AMainPlayerController::RequestAddScore()
{
	Server_AddScore();
}

void AMainPlayerController::Server_AddScore_Implementation()
{
	AMainPlayerState* MainPS = GetPlayerState<AMainPlayerState>();
	if (!MainPS)
		return;

	MainPS->AddScore(1);
}