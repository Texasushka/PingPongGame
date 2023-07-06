// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	MeshComponent->SetStaticMesh(CubeMesh.Object);
	MeshComponent->SetWorldScale3D(FVector(0.25f, 3, 0.25f));
	MeshComponent->SetRelativeScale3D(FVector(0.25f, 3, 0.25f));

	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("/Game/Materials/Player_M"));
	MeshComponent->SetMaterial(0, Material.Object);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraMain"));
	CameraComponent->SetRelativeRotation(FRotator(-90.f, 0.f, -90.f));
	CameraComponent->SetupAttachment(RootComponent);


	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 200.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->AttachTo(RootComponent);
	PlayerIndex = 0;

}

void APlayerPawn::SetPlayerIndex(int32 Index)
{
	PlayerIndex = Index;
	if (PlayerIndex == 1)
	{
		CameraComponent->SetRelativeLocation(FVector(-3000.f, 0, 5200.f));
	}
	else if(PlayerIndex == 2)
	{
		CameraComponent->SetRelativeLocation(FVector(3000.f, 0, 5200.f));
	}
}