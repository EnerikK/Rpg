// Hello

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "RPGEnemy.generated.h"

class UBehaviorTree;
class UWidgetComponent;
/**
 * 
 */
UCLASS()
class RPG_API ARPGEnemy : public ARPGCharacterBase
{
	GENERATED_BODY()

public:

	ARPGEnemy();
	
	virtual void PossessedBy(AController* NewController) override;

	/*
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly);
	TObjectPtr<UWidgetComponent> HealthBar;*/
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Class Defaults")
	int32 Level = 1;

	

	float BaseWalkSpeed = 250.f;


	
};
