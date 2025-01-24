#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MegaGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MEGA_API UMegaGameplayAbility : public UGameplayAbility {
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag StartupInputTag;
	
};
