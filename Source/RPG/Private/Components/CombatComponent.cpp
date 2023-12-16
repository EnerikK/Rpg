// Hello : )


#include "Components/CombatComponent.h"

#include "Character/RPGCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Weapons/WeaponsBase.h"


UCombatComponent::UCombatComponent()
{

	PrimaryComponentTick.bCanEverTick = false;
	
}
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UCombatComponent::EquipWeapon(AWeaponsBase* WeaponToEquip)
{
	if(Character == nullptr || WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EW_Equipped);
	const USkeletalMeshSocket* HandSocket = Character->GetMesh()->GetSocketByName(FName("WeaponHandSocket"));
	if(HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon,Character->GetMesh());
	}
	EquippedWeapon->SetOwner(Character);
	EquippedWeapon->ShowPickUpWidget(false);
	
}

