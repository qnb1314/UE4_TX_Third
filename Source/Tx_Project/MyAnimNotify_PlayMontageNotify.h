// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MyAnimNotify_PlayMontageNotify.generated.h"

/**
 * 
 */
UCLASS()
class TX_PROJECT_API UMyAnimNotify_PlayMontageNotify : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	UMyAnimNotify_PlayMontageNotify();

	UPROPERTY(EditAnywhere)
		FVector Injery_Size;

	UPROPERTY(EditAnywhere)
		bool If_Show_Debug;

	UPROPERTY(EditAnywhere)
		float Damage;

	TArray<FHitResult>HitResult;//存储每一次射线检测的命中结果
	TArray<AActor*>HitActor;//存储一次动画中所攻击到的Actor


	class ACharacter* Player;//在通知开始时调用，存储找到的角色实例指针
	class USkeletalMeshComponent* Right_Hand;//存储武器骨骼网络体


	FVector LastLocation_End;//记录上一帧剑端的位置
	FVector LastLocation_Center;//记录上一帧剑中间位置


	TArray<AActor*> Ignore;//设置射线检测时忽略的对象，这里默认设置只有自己


	//动画通知重载函数
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float TotalDuration)override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float FrameDeltaTime)override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation)override;
};
