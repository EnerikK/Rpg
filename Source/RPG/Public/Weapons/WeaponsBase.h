// Hello : )

#pragma once

#include "CoreMinimal.h"
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


UCLASS()
class RPG_API AWeaponsBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWeaponsBase();
	virtual void Tick(float DeltaTime) override;
	void ShowPickUpWidget(bool bShowWidget);

	FORCEINLINE void SetWeaponState(EWeaponState State) {WeaponState = State;}
	

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

	UPROPERTY(VisibleAnywhere,Category= "Weapon Properties")
	EWeaponState WeaponState;

	UPROPERTY(VisibleAnywhere,Category= "Weapon Properties")
	UWidgetComponent* PickUpWidget;

};
