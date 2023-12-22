// Hello : )

#pragma once

#include "CoreMinimal.h"
#include "SaoGameplayTags.h"
#include "GameFramework/Actor.h"
#include "WeaponsBase.generated.h"

class USphereComponent;
class UWidgetComponent;

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EW_Initial	UMETA(DisplayName = "InitialState"),
	EW_Equipped UMETA(DisplayName = "Equipped"),
	EW_Dropped	UMETA(DisplayName = "Dropped"),

	EW_MAX		UMETA(DisplayName = "DefaultMax")
	
};
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EW_GreatSword UMETA(DisplayName = "GreatSword"),
	EW_Daggers	  UMETA(DisplayName = "Daggers"),
	EW_Spear	  UMETA(DisplayName = "Spear"),
	EW_Staff	  UMETA(DisplayName = "Staff"),
};



UCLASS()
class RPG_API AWeaponsBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWeaponsBase();
	virtual void Tick(float DeltaTime) override;
	void ShowPickUpWidget(bool bShowWidget);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	void SetWeaponState(EWeaponState State);
	void SetWeaponType(EWeaponType Type);
	FORCEINLINE USphereComponent* GetPickUpSphere() const {return PickUpSphere;}

	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Tags")
	TArray<FName> Tag;
	

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlapComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(
		UPrimitiveComponent* OverlapComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);
	
private:

	UPROPERTY(VisibleAnywhere,Category= "Weapon Properties")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere,Category= "Weapon Properties")
	USphereComponent* PickUpSphere;

	UPROPERTY(ReplicatedUsing= OnRep_WeaponState,VisibleAnywhere,Category= "Weapon Properties")
	EWeaponState WeaponState;

	UPROPERTY(ReplicatedUsing= OnRep_WeaponType,EditDefaultsOnly,Category= "Weapon Properties")
	EWeaponType WeaponType;

	FSaoGameplayTags* GameplayTags;



	UFUNCTION()
	void OnRep_WeaponState();

	UFUNCTION()
	void OnRep_WeaponType();

	UPROPERTY(VisibleAnywhere,Category= "Weapon Properties")
	UWidgetComponent* PickUpWidget;

};



