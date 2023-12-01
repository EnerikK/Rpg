// Hello


#include "Character/RPGCharacterBase.h"

#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARPGCharacterBase::ARPGCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ARPGCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

