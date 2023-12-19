// Hello : )

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class ARPGCharacter;
/**
 * 
 */
UCLASS()
class RPG_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:

	UPROPERTY(BlueprintReadOnly, Category= "Character"  , meta=(AllowPrivateAccess = "true"))
	ARPGCharacter* Character;
	
	UPROPERTY(BlueprintReadOnly, Category= "Movement" , meta=(AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category= "Movement" , meta=(AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category= "Movement" , meta=(AllowPrivateAccess = "true"))
	bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly, Category= "Movement" , meta=(AllowPrivateAccess = "true"))
	bool bWeaponEquipped;
	
	UPROPERTY(BlueprintReadOnly, Category= "Movement" , meta=(AllowPrivateAccess = "true"))
	bool bIsCrouched;
	
};
