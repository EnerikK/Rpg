// Hello : )


#include "Weapons/WeaponsBase.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"



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

void AWeaponsBase::ShowPickUpWidget(bool bShowWidget)
{
	if(PickUpWidget)
	{
		PickUpWidget->SetVisibility(bShowWidget);
	}
}

