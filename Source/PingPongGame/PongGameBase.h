// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameBase.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGGAME_API APongGameBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    APongGameBase();

    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = "Pong")
        TSubclassOf<class APlayerPawn> PlayerPaddleClass;

    UPROPERTY(EditDefaultsOnly, Category = "Pong")
        TSubclassOf<class ABall> BallClass;

    UPROPERTY(EditDefaultsOnly, Category = "Pong")
        int32 WinningScore = 5;

    UFUNCTION(BlueprintCallable, Category = "Pong")
        void PlayerScored(int32 PlayerIndex);

    void HandleBallCollision(ABall* Ball, APlayerPawn* PlayerPawn);
    void MovePlayer1Paddle(float AxisValue);
    void MovePlayer2Paddle(float AxisValue);
private:


    int32 Player1Score = 0;
    int32 Player2Score = 0;
    void StartGame();
    void SpawnPaddles();
    void SpawnBall();
    void HandleWinningCondition();
    APlayerPawn* Player1Paddle;
    APlayerPawn* Player2Paddle;
    ABall* Ball;

    protected:
        virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
};


