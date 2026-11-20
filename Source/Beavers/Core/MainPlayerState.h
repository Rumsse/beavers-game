
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MainPlayerState.generated.h"


UCLASS()
class BEAVERS_API AMainPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void AddScore(int32 Amount);

	UFUNCTION(BlueprintPure, Category = "Player|Score")
	int32 GetPlayerScore() const { return PlayerScore; }

private:
	UPROPERTY(ReplicatedUsing = OnRep_PlayerScore)
	int32 PlayerScore = 0;

	UFUNCTION()
	void OnRep_PlayerScore();
	
};
