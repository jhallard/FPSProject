// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSGameMode.h"
#include "Engine.h" //for version 4.4+
#include "FPSCharacter.h"




AFPSGameMode::AFPSGameMode(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
//   DefaultPawnClass = AFPSCharacter::StaticClass();
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Blueprints/BP_FPSCharacter.BP_FPSCharacter_C'"));
      if (PlayerPawnObject.Class != NULL)
      {
          DefaultPawnClass = PlayerPawnObject.Class;
      }
}

// Note that engine version 4.3 changed the method's name to StartPlay(), because of this engine versions before 4.3, or older tutorials, use BeginPlay()
void AFPSGameMode::StartPlay() 
{
      Super::StartPlay();
 
      StartMatch();
 
      if (GEngine)
      {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
      }
}
