// Hello

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.generated.h"

UCLASS()
class RPG_API ARPGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ARPGCharacterBase();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere,Category="Combat")
	FName WeaponTipSocketName;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	FName LeftHandSocketName;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	FName RightHandSocketName;

	
	

	

};
