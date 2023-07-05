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

	protected:
		UFUNCTION()
		void Move(float Value);
		UPROPERTY(EditDefaultsOnly, Category = "Pong")
		float PaddleMovementSpeed = 300.0f;
};
