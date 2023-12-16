// Hello


#include "Player/RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CombatComponent.h"
#include "GameFramework/Character.h"


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
		JumpAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::StopJumping);

	EnhancedInputComponent->BindAction(
		CrouchAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Crouch);

	EnhancedInputComponent->BindAction(
		InteractAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Interact);
	
}
void ARPGPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveVector = Value.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0,Rotation.Yaw,0);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardVector,MoveVector.Y);
		ControlledPawn->AddMovementInput(RightVector,MoveVector.X);
	}
}

void ARPGPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
			// add yaw and pitch input to controller
			ControlledPawn->AddControllerYawInput(LookAxisVector.X);
			ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
		
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


