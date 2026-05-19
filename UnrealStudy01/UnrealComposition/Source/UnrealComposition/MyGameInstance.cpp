// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"


UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("=========================="));
	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };
	for (const auto Person : Persons)
	{
		const UCard* OwnCard = Person->GetCard();
		check(OwnCard);
		ECardType CardType = OwnCard->GetCardType();
		//UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %d"), *Person->GetName(), CardType);

		const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
		if (CardEnumType)
		{
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *Person->GetName(), *CardMetaData);
		}
	}
	
	UE_LOG(LogTemp, Log, TEXT("=========================="));
}




//컴포지션을 활용한 언리얼 오브젝트 설계
//1. 언리얼 C++은 컴포지션을 구현하는 독특한 패턴이 있다.
//2. 클래스 기본 객체를 생성하는 생성자 코드를 사용해 복잡한 언리얼 오브젝트를 생성할 수 있다.
//3. 언리얼 C++ 컴포지션의 Has - A 관계에 사용되는 용어
//- 내가 소유한 하위 오브젝트 Subobject
//- 나를 소유한 상위 오브젝트 : Outer
//4. 언리얼 C++이 제공하는 확장 열거형을 사용해 다양한 메타 정보를 넣고 활용할 수 있다.

//언리얼 C++의 컴포지션 기법은 게임의 복잡한 객체를 설계하고 생성할 때 유용하게 사용된다.