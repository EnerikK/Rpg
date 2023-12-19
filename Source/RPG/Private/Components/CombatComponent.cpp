// Hello : )


#include "Components/CombatComponent.h"
#include "Net/UnrealNetwork.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"
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

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent,EquippedWeapon);
	
}

void UCombatComponent::EquipWeapon(AWeaponsBase* WeaponToEquip)
{
	if(Character == nullptr || WeaponToEquip == nullptr) return;
	
	/*EWeaponType Weapon = EWeaponType::EW_GreatSword;
	if(EquippedWeapon->GetWeaponType())
	{*/
		EquippedWeapon = WeaponToEquip;
		EquippedWeapon->SetWeaponState(EWeaponState::EW_Equipped);
		const USkeletalMeshSocket* HandSocket = Character->GetMesh()->GetSocketByName(FName("RightHandSocketName"));
		if(HandSocket)
		{
			HandSocket->AttachActor(EquippedWeapon,Character->GetMesh());
		}
		EquippedWeapon->SetOwner(Character);
	/*}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Its a dagger"))
	}*/
	

}

