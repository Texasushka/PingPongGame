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

    // �������� �������� � �������� ��������� �����/����
    InputComponent->BindAxis("P1_Move", this, &APlayerControl::Move);
}

void APlayerControl::Move(float Value)
{
    if (Value != 0.0f)
    {
        // ��������� ������ �� ����������� ���������
        APlayerPawn* ControlledPaddle = Cast<APlayerPawn>(GetPawn());
        if (ControlledPaddle)
        {
            // ���������� ������� �������� ���������
            FVector MovementDirection = FVector(0.0f, 0.0f, Value) * PaddleMovementSpeed * GetWorld()->GetDeltaSeconds();

            // ���������� �������� � ���������
            ControlledPaddle->AddMovementInput(MovementDirection);
        }
    }
}