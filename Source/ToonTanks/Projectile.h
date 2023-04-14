// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "True"))
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float InitialSpeed = 2600.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed = 2600.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	float DamageAmount = 200.f;
};
