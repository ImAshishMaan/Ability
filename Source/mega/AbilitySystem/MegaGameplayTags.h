#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */

struct FMegaGameplayTags {
public:
 static const FMegaGameplayTags& Get() { return GameplayTags; }
 static void InitializeNativeGameplayTags();


 FGameplayTag InputTag_LMB;
 FGameplayTag InputTag_Q;
 FGameplayTag InputTag_E;
 FGameplayTag InputTag_F;
 FGameplayTag InputTag_G;
private:
 static FMegaGameplayTags GameplayTags;
};
