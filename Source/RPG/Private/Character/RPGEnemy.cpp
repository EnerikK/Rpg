// Hello


#include "Character/RPGEnemy.h"

#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ARPGEnemy::ARPGEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;


	/*HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());*/

	BaseWalkSpeed = 250.f;
}

void ARPGEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
}

void ARPGEnemy::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;

	
}
