// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class PINGPONGGAME_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	UFUNCTION(BlueprintCallable, Category = "Pong")
	void SetPlayerIndex(int32 Index);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnyWhere)
	class UBoxComponent* CollisionBox;
	UPROPERTY(VisibleAnyWhere)
	UCameraComponent * CameraComponent;
	int32 PlayerIndex;


};
