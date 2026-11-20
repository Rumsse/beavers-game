#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

UCLASS()
class BEAVERS_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Network|Test")
	void RequestAddScore();

private:
	UFUNCTION(Server, Reliable)
	void Server_AddScore();
};