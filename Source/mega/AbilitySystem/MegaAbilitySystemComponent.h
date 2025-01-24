#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MegaAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class MEGA_API UMegaAbilitySystemComponent : public UAbilitySystemComponent {
	GENERATED_BODY()

public:


	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
	
};
