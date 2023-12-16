#pragma once

#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "AbilityTypes.generated.h"


USTRUCT(BlueprintType)
struct FDamageEffectParams
{
	GENERATED_BODY()
	
	FDamageEffectParams(){}

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UObject> WorldContextObject = nullptr;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> DamageGameplayEffectClass = nullptr;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY(BlueprintReadWrite)
	float BaseDamage = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float AbilityLevel = 1.f;

	UPROPERTY(BlueprintReadWrite)
	FGameplayTag DamageType = FGameplayTag();
	
	UPROPERTY(BlueprintReadWrite)
	float DebuffChance = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float DebuffDamage =  0.f;

	UPROPERTY(BlueprintReadWrite)
	float DebuffDuration = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float DebuffFrequency = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float DeathImpulseMagnitude = 0.f;

	UPROPERTY(BlueprintReadWrite)
	FVector DeathImpulse = FVector::ZeroVector;
	
	UPROPERTY(BlueprintReadWrite)
	float KnockbackForceMagnitude = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float KnockbackChance = 0.f;

	UPROPERTY(BlueprintReadWrite)
	FVector KnockbackForce = FVector::ZeroVector;

};

USTRUCT(BlueprintType)
struct FWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AActor> EquippedWeaponObject;

	UPROPERTY(BlueprintReadWrite)
	float WeaponBaseDamage = 0.f;

	UPROPERTY(BlueprintReadWrite)
	int32 NumberOfComboAttacks = 4;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* ComboAttackAnimMontage1;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* ComboAttackAnimMontage2;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* ComboAttackAnimMontage3;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* ComboAttackAnimMontage4;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* DrawWeaponAnimMontage;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* SheatheWeaponAnimMontage;
	
};
