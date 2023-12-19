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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void EquipWeapon(AWeaponsBase* WeaponToEquip);

private:

	ARPGCharacter* Character;

	UPROPERTY(Replicated)
	AWeaponsBase* EquippedWeapon;

	bool bAttacking;

protected:
	
	virtual void BeginPlay() override;
	
};
