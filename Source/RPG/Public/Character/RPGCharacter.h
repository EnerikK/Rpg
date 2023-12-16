// Hello

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Character/RPGCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "RPGCharacter.generated.h"

class UCombatComponent;
class AWeaponsBase;
/**
 * 
 */
UCLASS()
class RPG_API ARPGCharacter : public ARPGCharacterBase
{
	GENERATED_BODY()

public:

	ARPGCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaSeconds) override;
	

	void SetOverlappingWeapon(AWeaponsBase* Weapon);

protected:

	void EquipButtonPressed();

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	AWeaponsBase* OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeaponsBase* LastWeapon);
	
	UPROPERTY(VisibleAnywhere)
	UCombatComponent* CombatComponent;

	
	

	
	
};
