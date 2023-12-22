// Hello : )


#include "Weapons/WeaponsBase.h"

#include "SaoGameplayTags.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"


AWeaponsBase::AWeaponsBase()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
	
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickUpSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickUpSphere"));
	PickUpSphere->SetupAttachment(RootComponent);
	PickUpSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	PickUpSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickUpWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickUpWidget"));
	PickUpWidget->SetupAttachment(RootComponent);

	WeaponType = EWeaponType::EW_Daggers;
	
	
}
void AWeaponsBase::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority())
	{
		PickUpSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		PickUpSphere->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
		PickUpSphere->OnComponentBeginOverlap.AddDynamic(this,&AWeaponsBase::OnSphereOverlap);
		PickUpSphere->OnComponentEndOverlap.AddDynamic(this,&AWeaponsBase::OnSphereEndOverlap);
	}

	if(PickUpWidget)
	{
		PickUpWidget->SetVisibility(false);
	}
	
}
void AWeaponsBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeaponsBase,WeaponState);
	DOREPLIFETIME(AWeaponsBase,WeaponType);
	
}

void AWeaponsBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AWeaponsBase::OnSphereOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(OtherActor);
	
	if(RPGCharacter && PickUpWidget)
	{
		RPGCharacter->SetOverlappingWeapon(this);
	}
}

void AWeaponsBase::OnSphereEndOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(OtherActor);
	
	if(RPGCharacter && PickUpWidget)
	{
		RPGCharacter->SetOverlappingWeapon(nullptr);
	}
	
}

void AWeaponsBase::SetWeaponState(EWeaponState State)
{
	WeaponState = State;
	switch (WeaponState)
	{
		case EWeaponState::EW_Equipped:
			ShowPickUpWidget(false);
			GetPickUpSphere()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}

	
}

void AWeaponsBase::SetWeaponType(EWeaponType Type)
{
	WeaponType = Type;
	WeaponType = EWeaponType::EW_Daggers;
	
}

void AWeaponsBase::OnRep_WeaponState()
{
	switch (WeaponState)
	{
		case EWeaponState::EW_Equipped:
			ShowPickUpWidget(false);
			PickUpSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}
	
}

void AWeaponsBase::OnRep_WeaponType()
{
	switch (WeaponType)
	{
		case EWeaponType::EW_GreatSword:
			
		break;
	}
	
}

void AWeaponsBase::ShowPickUpWidget(bool bShowWidget)
{
	if(PickUpWidget)
	{
		PickUpWidget->SetVisibility(bShowWidget);
	}
}


