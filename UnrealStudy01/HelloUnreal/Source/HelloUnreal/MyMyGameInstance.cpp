// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMyGameInstance.h"

void UMyMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal"));
}
