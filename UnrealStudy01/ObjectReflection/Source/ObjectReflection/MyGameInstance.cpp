// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("========================="));
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();
	//check(ClassRuntime == ClassCompile);     //==를 !=로 해서 실행하면 에디터가 꺼진다.
	//ensure(ClassRuntime != ClassCompile);		// 이것은 꺼지고 난 후 다시 키기 귀찮을때 사용한다.
	//ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부로 에러를 발생시킨 코드")); 

	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

	SchoolName = TEXT("청강문화산업대학교");

	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("========================="));

	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 %s"), *Student->GetName());

	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("이득우"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 %s"), *CurrentTeacherName);

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 %s"), *Teacher->GetName());
	}

	UE_LOG(LogTemp, Log, TEXT("========================="));

	Student->DoLesson();
	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if (DoLessonFunc)
	{
		Teacher->ProcessEvent(DoLessonFunc, nullptr);
	}

	UE_LOG(LogTemp, Log, TEXT("========================="));

	// 언리얼 리플렉션 시스템의 활용
	// 리플렉션 시스템을 사용해 언리얼 오브젝트의 특정 속성과 함수를 이름으로 검색할 수 있다.
	// 리플렉션 시스템을 사용해 접근 지시자와 무관하게 값을 설정할 수 있다.
	// 리플렉션 시스템을 사용해 언리얼 오브젝트의 함수를 호출할 수 있다.

	// 언리얼 엔진의 기본 프레임웍은 리플렉션을 활용해 구축되어 있으므로
	// 언리얼 엔진을 이해하기 위해서는 리플렉션 시스템을 이해하는 것이 필요함
}
