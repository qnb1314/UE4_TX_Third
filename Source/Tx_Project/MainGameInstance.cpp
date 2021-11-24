// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"


UMainGameInstance* UMainGameInstance::instance = nullptr;

void UMainGameInstance::endattack()
{
	EndAttackEvent.Broadcast();
}

void UMainGameInstance::emitEvent()
{
	testEvent.Broadcast();
	testEvent.Broadcast();
}

void UMainGameInstance::OnStart()
{
	instance = this;
}