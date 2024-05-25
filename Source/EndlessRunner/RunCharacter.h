// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "RunCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "ture"))
	class USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "ture"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
	class AEndlessRunnerGameModeBase* RunGameMode;

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	int32 CurrentLane = 1;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	int32 NextLane;

	UFUNCTION(BlueprintImplementableEvent, Category = "Lane")
	void ChangeLane();

	UFUNCTION(BlueprintCallable, Category = "Lane")
	void ChangeLaneUpdate(float Value);

	UFUNCTION(BlueprintCallable, Category = "Lane")
	void ChangeLaneFinished();

	// Sets default values for this character's properties
	ARunCharacter();

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* IMC_Default;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_MoveRight; 

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_MoveLeft;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_MoveDown;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_Jump;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(const FInputActionValue& Value);
	void MoveLeft(const FInputActionValue& Value);
	void MoveDown(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
