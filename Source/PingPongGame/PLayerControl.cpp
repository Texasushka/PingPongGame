// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControl.h"
#include "PlayerPawn.h"

APlayerControl::APlayerControl()
{
	bShowMouseCursor = false;
}


void APlayerControl::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Привязка действия к движению платформы вверх/вниз
    InputComponent->BindAxis("P1_Move", this, &APlayerControl::Move);
}

void APlayerControl::Move(float Value)
{
    if (Value != 0.0f)
    {
        // Получение ссылки на управляемую платформу
        APlayerPawn* ControlledPaddle = Cast<APlayerPawn>(GetPawn());
        if (ControlledPaddle)
        {
            // Вычисление вектора движения платформы
            FVector MovementDirection = FVector(0.0f, 0.0f, Value) * PaddleMovementSpeed * GetWorld()->GetDeltaSeconds();

            // Применение движения к платформе
            ControlledPaddle->AddMovementInput(MovementDirection);
        }
    }
}