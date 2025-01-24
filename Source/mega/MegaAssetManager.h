// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MegaAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class MEGA_API UMegaAssetManager : public UAssetManager {
	GENERATED_BODY()

public:

	static UMegaAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
