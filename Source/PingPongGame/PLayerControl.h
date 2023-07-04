// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PLayerControl.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGGAME_API APLayerControl : public APlayerController
{
	GENERATED_BODY()
	
	public:
	void MoveUp();
	void MoveDown();
};
