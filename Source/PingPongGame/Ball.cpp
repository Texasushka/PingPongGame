// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	CurrentVelocity = FVector(100.0f, 300.0f, 0.0f);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = this->GetActorLocation();
	FVector NewLocation = CurrentLocation + (CurrentVelocity*DeltaTime);
	if (NewLocation.Y < 560 && NewLocation.Y > -560)
	{
		this->SetActorLocation(NewLocation);
	}
	else 
		CurrentVelocity.Y *= -1;

	
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp)
{
    // При соприкосновении сопоставляемого актера с другим компонентом

    if (OtherActor && OtherActor != this)
    {
        FVector NewVelocity = CurrentVelocity * -1;

        // Применяем новую скорость мячика
        CurrentVelocity = NewVelocity;
    }
}