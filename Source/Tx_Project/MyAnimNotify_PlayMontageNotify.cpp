// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimNotify_PlayMontageNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"
#include "MainGameInstance.h"

UMyAnimNotify_PlayMontageNotify::UMyAnimNotify_PlayMontageNotify()
{
	Injery_Size = FVector(5, 30, 50);
	If_Show_Debug = 1;
}

void UMyAnimNotify_PlayMontageNotify::NotifyBegin(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float TotalDuration)
{
	//首先根据MeshComb得到当前动画的角色
	Player = Cast<ACharacter>(MeshComb->GetOwner());

	if (Player)
	{
		Right_Hand = Cast<USkeletalMeshComponent>(MeshComb->GetChildComponent(0));
		Ignore = { MeshComb->GetOwner() };
		LastLocation_End = Right_Hand->GetSocketLocation("trailEnd");
		LastLocation_Center = Right_Hand->GetSocketLocation("trailCenter");
	}
}

void UMyAnimNotify_PlayMontageNotify::NotifyTick(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (Player)
	{
		FVector NowLocation_End = Right_Hand->GetSocketLocation("trailEnd");
		FVector NowLocation_Center = Right_Hand->GetSocketLocation("trailCenter");

		//调用射线检测函数
		//1.检测剑端弧线矩形块
		if (If_Show_Debug)
		{
			UKismetSystemLibrary::BoxTraceMulti(Player->GetWorld(), LastLocation_End, NowLocation_End,
				Injery_Size, Right_Hand->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery4, false, Ignore, EDrawDebugTrace::ForDuration, HitResult, true);
		}
		else
		{
			UKismetSystemLibrary::BoxTraceMulti(Player->GetWorld(), LastLocation_End, NowLocation_End,
				Injery_Size, Right_Hand->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery4, false, Ignore, EDrawDebugTrace::None, HitResult, true);
		}

		for (int i = 0; i < HitResult.Num(); i++)
		{
			AActor* hit_actor = HitResult[i].GetActor();
			if (!HitActor.Contains(hit_actor))
			{
				HitActor.Add(hit_actor);
				ACharacter* target = Cast<ACharacter>(hit_actor);

				if (target)
				{
					UMainGameInstance::instance->Injury_Event.Broadcast(hit_actor, Damage);
				}
			}
		}

		//2.检测剑中心弧线矩形块
		if (If_Show_Debug)
		{
			UKismetSystemLibrary::BoxTraceMulti(Player->GetWorld(), LastLocation_Center, NowLocation_Center,
				Injery_Size, Right_Hand->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery4, false, Ignore, EDrawDebugTrace::ForDuration, HitResult, true);
		}
		else
		{
			UKismetSystemLibrary::BoxTraceMulti(Player->GetWorld(), LastLocation_Center, NowLocation_Center,
				Injery_Size, Right_Hand->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery4, false, Ignore, EDrawDebugTrace::None, HitResult, true);
		}


		for (int i = 0; i < HitResult.Num(); i++)
		{
			AActor* hit_actor = HitResult[i].GetActor();
			if (!HitActor.Contains(hit_actor))
			{
				HitActor.Add(hit_actor);

				ACharacter* target = Cast<ACharacter>(hit_actor);

				if (target)
				{
					UMainGameInstance::instance->Injury_Event.Broadcast(hit_actor, Damage);
				}

			}
		}


		LastLocation_End = NowLocation_End;
		LastLocation_Center = NowLocation_Center;

	}
}

void UMyAnimNotify_PlayMontageNotify::NotifyEnd(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation)
{
	HitResult.Empty();
	HitActor.Empty();
	Ignore.Empty();

	Player = NULL;
	Right_Hand = NULL;
}