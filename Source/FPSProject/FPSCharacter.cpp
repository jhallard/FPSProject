// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSCharacter.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPSCharacter::BeginPlay()
{
      Super::BeginPlay();
 
      if (GEngine)
      {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using FPSCharacter!"));
      }
}

// Called every frame
void AFPSCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
// void AFPSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
// {
// 	Super::SetupPlayerInputComponent(InputComponent);
// 
// }
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
  // set up gameplay key bindings
  InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
  InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
  InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
  InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
  InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::OnStartJump);
  InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::OnStopJump);
}

void AFPSCharacter::MoveForward(float Value)
{
    if ( (Controller != NULL) && (Value != 0.0f) )
    {
	// find out which way is forward
	FRotator Rotation = Controller->GetControlRotation();
	// Limit pitch when walking or falling
	if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() )
	{
	    Rotation.Pitch = 0.0f;
	}
	// add movement in that direction
	const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
    }
}

void AFPSCharacter::MoveRight(float Value)
{
    if ( (Controller != NULL) && (Value != 0.0f) )
    {
	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
	// add movement in that direction
	AddMovementInput(Direction, Value);
    }
}

void AFPSCharacter::OnStartJump()
{
    bPressedJump = true;
}
void AFPSCharacter::OnStopJump()
{
    bPressedJump = false;
}
