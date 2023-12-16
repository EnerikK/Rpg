// Hello : )

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class AWeaponsBase;
class ARPGCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCombatComponent();
	friend class ARPGCharacter;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void EquipWeapon(AWeaponsBase* WeaponToEquip);

private:

	ARPGCharacter* Character;
	AWeaponsBase* EquippedWeapon;

protected:
	
	virtual void BeginPlay() override;
	
};
