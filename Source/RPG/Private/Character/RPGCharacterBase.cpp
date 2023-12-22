// Hello


#include "Character/RPGCharacterBase.h"

#include "SaoGameplayTags.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARPGCharacterBase::ARPGCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	const FSaoGameplayTags& GameplayTags = FSaoGameplayTags::Get();

	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ARPGCharacterBase::OpenLobby()
{
	UWorld* World = GetWorld();
	if(World)
	{
		World->ServerTravel("/Game/Blueprints/Map/Lobby?listen");
	}
	
}

void ARPGCharacterBase::CallOpenLevel(const FString& Address)
{
	UGameplayStatics::OpenLevel(this,*Address);
	
	
}

void ARPGCharacterBase::CallClientTravel(const FString& Address)
{
	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if(PlayerController)
	{
		PlayerController->ClientTravel(Address,TRAVEL_Absolute);
	}
}
void ARPGCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}


void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPGCharacterBase::InitAbilityActorInfo()
{
}

