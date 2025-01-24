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
 FGameplayTag InputTag_RMB;
 FGameplayTag InputTag_1;
 FGameplayTag InputTag_2;
 FGameplayTag InputTag_3;
 FGameplayTag InputTag_4;
private:
 static FMegaGameplayTags GameplayTags;
};
