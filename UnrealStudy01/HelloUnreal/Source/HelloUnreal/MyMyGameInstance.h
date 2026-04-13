// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameInstance.h"
#include "MyMyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UMyMyGameInstance : public UMyGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
	
};
