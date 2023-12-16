// Hello


#include "Character/RPGCharacter.h"
#include "Components/CombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Components/InputComponent.h"
#include "Weapons/WeaponsBase.h"

ARPGCharacter::ARPGCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	CombatComponent->SetIsReplicated(true);

}

void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("EquipButtonPressed",IE_Pressed,this,&ARPGCharacter::EquipButtonPressed);
}

void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
}
void ARPGCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void ARPGCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(CombatComponent)
	{
		CombatComponent->Character = this;
	}
	
}

void ARPGCharacter::SetOverlappingWeapon(AWeaponsBase* Weapon)
{
	if(OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickUpWidget(false);
		
	}
	OverlappingWeapon = Weapon;
	if(IsLocallyControlled())
	{
		if(OverlappingWeapon)
		{
			OverlappingWeapon->ShowPickUpWidget(true);
		
		}
	}
	
}

void ARPGCharacter::OnRep_OverlappingWeapon(AWeaponsBase* LastWeapon)
{
	if(OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickUpWidget(true);
		
	}
	if(LastWeapon)
	{
		LastWeapon->ShowPickUpWidget(false);
	}
}

void ARPGCharacter::EquipButtonPressed()
{
	if(CombatComponent && HasAuthority())
	{
		CombatComponent->EquipWeapon(OverlappingWeapon);
	}
}

void ARPGCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ARPGCharacter,OverlappingWeapon,COND_OwnerOnly);
}



void ARPGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ARPGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

