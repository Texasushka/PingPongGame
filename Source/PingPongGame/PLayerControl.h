// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControl.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGGAME_API APlayerControl : public APlayerController
{
	GENERATED_BODY()
	
	public:
	APlayerControl();
	virtual void SetupInputComponent() override;
	void SetPlayerController(APlayerControl* Controller);
		UFUNCTION()
		void Move(float Value);
		UPROPERTY(EditDefaultsOnly, Category = "Pong")
		float PaddleMovementSpeed = 300.0f;
		int32 PlayerIndex;
		APlayerControl* PlayerController;
};
