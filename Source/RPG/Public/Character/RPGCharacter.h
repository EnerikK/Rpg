// Hello

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Character/RPGCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "RPGCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGCharacter : public ARPGCharacterBase
{
	GENERATED_BODY()

public:

	ARPGCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	
};
