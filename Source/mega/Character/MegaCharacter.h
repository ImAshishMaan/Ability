#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemInterface.h"
#include "InputAction.h"
#include "CoreMinimal.h"
#include "mega/Interfaces/AnimationInterface.h"
#include "MegaCharacter.generated.h"

class UMegaAbilitySystemComponent;
struct FGameplayTag;
class UMegaInputConfig;
class UGameplayAbility;
class UAttributeSet;
class UAbilitySystemComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class MEGA_API AMegaCharacter : public ACharacter, public IAnimationInterface, public IAbilitySystemInterface {
	GENERATED_BODY()

public:
	AMegaCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	void SetWalkState();
	void SetJogState();
	void SetCrouchState();
	void SetGroundDistance();

	/*
	 * Animation Layers Data 
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimLayers")
	EEquipped CurrentEquipped = EEquipped::UnEquipped;
	EEquipped LastEquipped = EEquipped::Rifle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimLayers")
	TMap<EEquipped, TSubclassOf<UAnimInstance>> AnimInstanceMap;

	void SetAnimLayer();

	/*
	 * 
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterState")
	ECharacterState CurrentState = ECharacterState::Jogging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gate Settings")
	TMap<ECharacterState, FCharacterSettings> StateSettingsMap;

	UFUNCTION(BlueprintCallable)
	void SetCharacterStates();

	UFUNCTION(BlueprintCallable)
	void UpdateCharacterStateWithSettings(ECharacterState NewState);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	void AddMappingContext();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartJumping();
	virtual void StopJumping() override;

protected:
	virtual void BeginPlay() override;

	void AddCharacterAbilities();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;


	/*
	 * Ability Array
	 */
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;


	/*
	 * Inputs should be in controller class
	 */
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UMegaInputConfig> InputConfig;

};
