// Hello : )

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"


/*
 * GameplayTags
 * 
 * Singleton Containing GameplayTags
 */

struct FSaoGameplayTags
{
public:
	
	static const FSaoGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeGameplayTags();

	/*
	 * WeaponTags
	 */
	FGameplayTag Weapon_GreatSword;
	FGameplayTag Weapon_Daggers;
	FGameplayTag Weapon_Spear;
	FGameplayTag Weapon_Staff;
 


private:

	static FSaoGameplayTags GameplayTags;

 
};
