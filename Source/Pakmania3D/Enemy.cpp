// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "AITypes.h"
#include "Components/SphereComponent.h"
#include "Pakmania3DCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AggroSphere"));
	AggroSphere->SetupAttachment(GetRootComponent());
	AggroSphere->InitSphereRadius(1000.f);

	bIsLookingForTarget = true;

	GetCharacterMovement()->MaxWalkSpeed = (GetCharacterMovement()->MaxWalkSpeed / 3.f);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	if(AggroSphere)
	{
		AggroSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::AggroSphereOnOverlapBegin);
		AggroSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy::AggroSphereOnOverlapEnd);
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::AggroSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		APakmania3DCharacter* PlayerChar = Cast<APakmania3DCharacter>(OtherActor);
		//Insert functionality to chase the player
	}
}

void AEnemy::AggroSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		APakmania3DCharacter* PlayerChar = Cast<APakmania3DCharacter>(OtherActor);
	}
}


