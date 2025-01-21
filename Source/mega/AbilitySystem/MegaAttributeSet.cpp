#include "MegaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UMegaAttributeSet::UMegaAttributeSet() {
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}

void UMegaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMegaAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMegaAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UMegaAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMegaAttributeSet, Health, OldHealth);
}

void UMegaAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMegaAttributeSet, MaxHealth, OldMaxHealth);
}
