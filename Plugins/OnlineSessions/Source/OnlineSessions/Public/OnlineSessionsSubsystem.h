// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ONLINESESSIONS_API UOnlineSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UOnlineSessionsSubsystem();
protected:

private:
	IOnlineSessionPtr SessionInterface;
	
	
};
