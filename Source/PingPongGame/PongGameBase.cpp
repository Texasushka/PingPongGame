// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameBase.h"
#include "PlayerPawn.h"
#include "PlayerControl.h"
#include "Ball.h"

APongGameBase::APongGameBase()
{
    // Установка классов игроков
    PlayerControllerClass = APlayerControl::StaticClass();
    DefaultPawnClass = nullptr;

}

void APongGameBase::BeginPlay()
{
    Super::BeginPlay();

    // Создание платформ и мяча
    //StartGame();
    SpawnBall();
    SpawnPaddles();
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

    // Создание платформ для игроков
    Player1Paddle = GetWorld()->SpawnActor<APlayerPawn>(Player1Location, FRotator::ZeroRotator);
    Player2Paddle = GetWorld()->SpawnActor<APlayerPawn>(Player2Location, FRotator::ZeroRotator);

    // Установка начальных параметров платформ
    Player1Paddle->SetPlayerIndex(1);
    Player2Paddle->SetPlayerIndex(2);
}

void APongGameBase::SpawnBall()
{

    FVector BallLocation = FVector(0.0f, 0.0f, 70.0f);

    Ball = GetWorld()->SpawnActor<ABall>(BallLocation, FRotator::ZeroRotator);

    //Ball->SetInitialVelocity();
}

void APongGameBase::PlayerScored(int32 PlayerIndex)
{
    // Увеличение счета игрока
    if (PlayerIndex == 1)
    {
        Player1Score++;
    }
    else if (PlayerIndex == 2)
    {
        Player2Score++;
    }

    // Проверка на победу
    if (Player1Score >= WinningScore || Player2Score >= WinningScore)
    {
        // Обработка победы
        HandleWinningCondition();
    }
    else
    {
        // Перезапуск мяча после очка
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