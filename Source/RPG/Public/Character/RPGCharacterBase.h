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

	UFUNCTION(BlueprintCallable)
	void OpenLobby();
	
	UFUNCTION(BlueprintCallable)
	void CallOpenLevel(const FString& Address);

	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& Address);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere,Category="Combat")
	FName WeaponTipSocketName;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	FName LeftHandSocketName;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	FName RightHandSocketName;

	
	

	

};
