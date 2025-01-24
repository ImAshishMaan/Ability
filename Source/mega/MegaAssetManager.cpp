#include "MegaAssetManager.h"
#include "AbilitySystem/MegaGameplayTags.h"

UMegaAssetManager& UMegaAssetManager::Get() {
	check(GEngine);
	
	UMegaAssetManager* AuraAssetManager = Cast<UMegaAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UMegaAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();
	
	FMegaGameplayTags::InitializeNativeGameplayTags();
}
