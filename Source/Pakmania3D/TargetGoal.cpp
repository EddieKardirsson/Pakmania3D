// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetGoal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Enemy.h"

// Sets default values
ATargetGoal::ATargetGoal()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Mesh->SetupAttachment(GetRootComponent());

	SphereRange = CreateDefaultSubobject<USphereComponent>(TEXT("SphereOfRange"));
	SphereRange->SetupAttachment(Mesh);
	SphereRange->InitSphereRadius(80.f);

	TargetID = 0;
}

// Called when the game starts or when spawned
void ATargetGoal::BeginPlay()
{
	Super::BeginPlay();

	if(SphereRange)
	{
		SphereRange->OnComponentBeginOverlap.AddDynamic(this, &ATargetGoal::SphereOnComponentBeginOverlap);
		SphereRange->OnComponentEndOverlap.AddDynamic(this, &ATargetGoal::SphereOnComponentEndOverlap);
	}
}

// Called every frame
void ATargetGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATargetGoal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATargetGoal::SphereOnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AEnemy* Enemy=Cast<AEnemy>(OtherActor);
		if(Enemy)
		{
			Enemy->bIsLookingForTarget = false;
		}
	}
}

void ATargetGoal::SphereOnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

