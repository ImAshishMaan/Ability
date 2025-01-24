#include "MegaAbilitySystemComponent.h"
#include "Ability/MegaGameplayAbility.h"

void UMegaAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities) {
	for(TSubclassOf<UGameplayAbility> AbilityClass: StartupAbilities) {
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);

		if(const UMegaGameplayAbility* AuraAbility = Cast<UMegaGameplayAbility>(AbilitySpec.Ability)) {
			AbilitySpec.DynamicAbilityTags.AddTag(AuraAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UMegaAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag) {
	if(!InputTag.IsValid()) return;
	
	for(FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities()) {
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) {
			AbilitySpecInputPressed(AbilitySpec);
			if(!AbilitySpec.IsActive()) {
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UMegaAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag) {
	if(!InputTag.IsValid()) return;
	
	for(FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities()) {
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) {
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}
