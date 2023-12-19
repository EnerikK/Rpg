// Hello : )

#include "SaoGameplayTags.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

FSaoGameplayTags FSaoGameplayTags::GameplayTags;

void FSaoGameplayTags::InitializeNativeGameplayTags()
{
	/*WeaponTags*/
	GameplayTags.Weapon_GreatSword = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Weapon.GreatSword"),
		FString("Tag for GreatSwords"));
	
	GameplayTags.Weapon_Daggers = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Weapon.Daggers"),
		FString("Tag for Daggers"));
	
	GameplayTags.Weapon_Spear = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Weapon.Spear"),
		FString("Tag for Spear"));
	
	GameplayTags.Weapon_Staff = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Weapon.Staff"),
		FString("Tag for Staff"));
	/*WeaponTags End*/
	
}
