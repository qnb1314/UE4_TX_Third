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

	TArray<FHitResult>HitResult;//�洢ÿһ�����߼������н��
	TArray<AActor*>HitActor;//�洢һ�ζ���������������Actor


	class ACharacter* Player;//��֪ͨ��ʼʱ���ã��洢�ҵ��Ľ�ɫʵ��ָ��
	class USkeletalMeshComponent* Right_Hand;//�洢��������������


	FVector LastLocation_End;//��¼��һ֡���˵�λ��
	FVector LastLocation_Center;//��¼��һ֡���м�λ��


	TArray<AActor*> Ignore;//�������߼��ʱ���ԵĶ�������Ĭ������ֻ���Լ�


	//����֪ͨ���غ���
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float TotalDuration)override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation, float FrameDeltaTime)override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComb, UAnimSequenceBase* Animation)override;
};
