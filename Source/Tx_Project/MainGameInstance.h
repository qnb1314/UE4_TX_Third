// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FdefaultEvent);//Ĭ���¼�,�޲���
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInjury, AActor*, MyActor,float,Damage);//���˺��ж�ί�У����뱻�˺���Actor


UCLASS()
class TX_PROJECT_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	//����ʱ��ֵinstance
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
