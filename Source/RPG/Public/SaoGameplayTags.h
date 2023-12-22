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


	/*PlayerTags*/
	FGameplayTag Player_Block_Cursor_Trace;
 


private:

	static FSaoGameplayTags GameplayTags;

 
};
