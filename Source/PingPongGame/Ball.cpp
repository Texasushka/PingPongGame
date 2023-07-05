// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#define MAX_VELOCITY = 1800.f;

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	MeshComponent->SetStaticMesh(SphereMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("/Game/Materials/Ball_M"));
	MeshComponent->SetMaterial(0, Material.Object);

	CurrentVelocity = FVector(100.0f, 300.0f, 0.0f);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f,32.f,32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->AttachTo(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlapBegin);
	//CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABall::OnOverlapEnd);
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

	if ((CurrentVelocity.X + CurrentVelocity.Y + CurrentVelocity.Z) > 1800.f)
	{

	}

	if (NewLocation.Y < 530 && NewLocation.Y > -530)
	{
		this->SetActorLocation(NewLocation);
	}
	else 
		CurrentVelocity.Y *= -1;
	if (NewLocation.X < 850 && NewLocation.X > -850)
	{
		this->SetActorLocation(NewLocation);
	}
	else
		CurrentVelocity.X *= -1;
	
}


void ABall::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
CurrentVelocity.X *= -1;
}

void ABall::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABall::ResetBall()
{
	this->SetActorLocation(FVector(0.f,0.f,0.f));
}

void ABall::SetInitialVelocity()
{
	CurrentVelocity = FVector(0.f,300.f,0.f);
}
