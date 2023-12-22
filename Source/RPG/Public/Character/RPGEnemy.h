// Hello

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RPGEnemy.generated.h"

class UBehaviorTree;
class UWidgetComponent;
/**
 * 
 */
UCLASS()
class RPG_API ARPGEnemy : public ARPGCharacterBase , public IEnemyInterface
{
	GENERATED_BODY()

public:

	ARPGEnemy();
	virtual void PossessedBy(AController* NewController) override;

	/*EnemyInterface*/
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/*EnemyInterfaceEnd*/
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Class Defaults")
	int32 Level = 1;

	

	float BaseWalkSpeed = 250.f;


	
};
