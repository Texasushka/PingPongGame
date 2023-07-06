// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameBase.h"
#include "Engine.h"
#include "PlayerPawn.h"
#include "PlayerControl.h"
#include "Ball.h"




APongGameBase::APongGameBase()
{
    bUseSeamlessTravel = true;
    PlayerControllerClass = APlayerControl::StaticClass();
    DefaultPawnClass = nullptr;

}

void APongGameBase::BeginPlay()
{
    Super::BeginPlay();
    StartGame();
}


void APongGameBase::StartGame()
{
    Player1Score = 0;
    Player2Score = 0;

    SpawnPaddles();
    SpawnBall();
}

void APongGameBase::SpawnPaddles()
{

    FVector Player1Location = FVector(770.f, 0.0f, 40.0f);
    FVector Player2Location = FVector(-770.f, 0.0f, 40.0f);
    if (GetLocalRole() == ROLE_Authority)
    {
        Player1Paddle = GetWorld()->SpawnActor<APlayerPawn>(Player1Location, FRotator::ZeroRotator);
        Player1Paddle->SetPlayerIndex(1);
        /*APlayerController* Player1Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
        Player1Controller->Possess(Player1Paddle);*/

        Player2Paddle = GetWorld()->SpawnActor<APlayerPawn>(Player2Location, FRotator::ZeroRotator);
        Player2Paddle->SetPlayerIndex(2);
        /*APlayerController* Player2Controller = UGameplayStatics::GetPlayerController(GetWorld(), 1);
        Player2Controller->Possess(Player2Paddle);*/
    }

}

void APongGameBase::SpawnBall()
{

    FVector BallLocation = FVector(0.0f, 0.0f, 70.0f);

    Ball = GetWorld()->SpawnActor<ABall>(BallLocation, FRotator::ZeroRotator);
}

void APongGameBase::PlayerScored(int32 PlayerIndex)
{
    if (PlayerIndex == 1)
    {
        Player1Score++;
    }
    else if (PlayerIndex == 2)
    {
        Player2Score++;
    }

    if (Player1Score >= WinningScore || Player2Score >= WinningScore)
    {
        HandleWinningCondition();
    }
    else
    {
        Ball->ResetBall();
    }
}

void APongGameBase::HandleWinningCondition()
{
    // Обработка победы
    if (Player1Score >= WinningScore)
    {
        // Игрок 1 победил
    }
    else if (Player2Score >= WinningScore)
    {
        // Игрок 2 победил
    }
}

void APongGameBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

    if (GetNetMode() == NM_Client)
    {
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
        if (PlayerController)
        {
            PlayerController->DisableInput(PlayerController);
        }
    }
}
