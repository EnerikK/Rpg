// Hello


#include "Player/RPGPlayerController.h"
#include "AbilitySystem/SaoAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SaoGameplayTags.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "Interaction/EnemyInterface.h"


ARPGPlayerController::ARPGPlayerController()
{
	bReplicates = true;

}

void ARPGPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(PlayerContext,0);
	}

	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(
		MoveAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Move);
		
	EnhancedInputComponent->BindAction(
		LookAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Look);
		
	EnhancedInputComponent->BindAction(
		JumpAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Jump);
	
	EnhancedInputComponent->BindAction(
		CrouchAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Crouch);

	EnhancedInputComponent->BindAction(
		InteractAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Interact);
	
	EnhancedInputComponent->BindAction(
		ShowCursor,ETriggerEvent::Triggered,this,&ARPGPlayerController::EnableCursor);
	
	
	
}
void ARPGPlayerController::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	APawn* ControlledPawn = GetPawn<APawn>();
	
	if (ControlledPawn != nullptr)
	{
		const FVector2D MoveValue = Value.Get<FVector2D>();
		const FRotator MovementRotation(0, ControlledPawn->GetControlRotation().Yaw, 0);
 
		// Forward/Backward direction
		if (MoveValue.Y != 0.f)
		{
			// Get forward vector
			const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
			
			ControlledPawn->AddMovementInput(Direction, MoveValue.Y);
		}
 
		// Right/Left direction
		if (MoveValue.X != 0.f)
		{
			// Get right vector
			const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
 
			ControlledPawn->AddMovementInput(Direction, MoveValue.X);
		}
	}
}
void ARPGPlayerController::Look(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn<APawn>();
	
	if (ControlledPawn->Controller != nullptr)
	{
		const FVector2D LookValue = Value.Get<FVector2D>();
 
		if (LookValue.X != 0.f)
		{
			ControlledPawn->AddControllerYawInput(LookValue.X);
			
		}
 
		if (LookValue.Y != 0.f)
		{
			ControlledPawn->AddControllerPitchInput(LookValue.Y);
		}
	}
}
void ARPGPlayerController::Jump(const FInputActionValue& Value)
{
	if(ACharacter* ControlledCharacter = GetPawn<ACharacter>())
	{
		ControlledCharacter->Jump();
	}
}
void ARPGPlayerController::StopJumping(const FInputActionValue& Value)
{
}

void ARPGPlayerController::Crouch(const FInputActionValue& Value)
{
	
}

void ARPGPlayerController::Interact(const FInputActionValue& Value)
{
}

void ARPGPlayerController::EnableCursor(const FInputActionValue& Value)
{
	if(!bShowMouseCursor)
	{
		bShowMouseCursor = true;
	}
	else
	{
		bShowMouseCursor = false;
	}
}

void ARPGPlayerController::CursorTrace()
{
	if(GetASC() && GetASC()->HasMatchingGameplayTag(FSaoGameplayTags::Get().Player_Block_Cursor_Trace))
	{
		if(LastActor) LastActor->UnHighLightActor();
		if(ThisActor) ThisActor->HighLightActor();
		LastActor = nullptr;
		ThisActor = nullptr;
		return;
	}
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if(!CursorHit.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	if(LastActor != ThisActor)
	{
		if(LastActor) LastActor->UnHighLightActor();
		if(ThisActor) ThisActor->HighLightActor();
	}
}

USaoAbilitySystemComponent* ARPGPlayerController::GetASC()
{
	if(SaoAbilitySystemComponent == nullptr)
	{
		SaoAbilitySystemComponent = Cast<USaoAbilitySystemComponent>
		(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return SaoAbilitySystemComponent;
}


