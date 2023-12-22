// Hello

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "AbilitySystem/SaoAbilitySystemComponent.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class IEnemyInterface;
class UCombatComponent;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ARPGPlayerController();
	virtual void Tick(float DeltaSeconds) override;


protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
	FHitResult CursorHit;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> CrouchAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> ShowCursor;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void StopJumping(const FInputActionValue& Value);
	void Crouch(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	void EnableCursor(const FInputActionValue& Value);

	void CursorTrace();

	UPROPERTY()
	TObjectPtr<USaoAbilitySystemComponent> SaoAbilitySystemComponent;
	
	USaoAbilitySystemComponent* GetASC();
	
};
