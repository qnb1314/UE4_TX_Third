// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FdefaultEvent);//默认事件,无参数
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInjury, AActor*, MyActor,float,Damage);//简单伤害判定委托，传入被伤害的Actor


UCLASS()
class TX_PROJECT_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	//启动时赋值instance
	void OnStart()override;
public:
	UPROPERTY(BlueprintAssignable, Category = "my_event")
		FdefaultEvent testEvent;
	UPROPERTY(BlueprintAssignable, Category = "my_event")
		FdefaultEvent EndAttackEvent;

	UFUNCTION(BlueprintCallable, Category = "my_event")
		void endattack();
	UFUNCTION(BlueprintCallable, Category = "my_event")
		void emitEvent();
	UPROPERTY(BlueprintAssignable, Category = "my_event")
		FInjury Injury_Event;
public:
	static UMainGameInstance* instance;
	
};
