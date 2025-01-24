// Fill out your copyright notice in the Description page of Project Settings.


#include "MegaGameplayTags.h"
#include "GameplayTagsManager.h"

FMegaGameplayTags FMegaGameplayTags::GameplayTags;

void FMegaGameplayTags::InitializeNativeGameplayTags() {
	/*
	* Input Tags
	*/

	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.LMB"),
		FString("Input Tag for Left Mouse Button")
	);
	
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.RMB"),
		FString("Input Tag for Right Mouse Button")
	);
	
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.Q"),
		FString("Input Tag for Q key")
	);
	
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.E"),
		FString("Input Tag for E key")
	);
	
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.F"),
		FString("Input Tag for F key")
	);
	
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.G"),
		FString("Input Tag for G key")
	);
}
