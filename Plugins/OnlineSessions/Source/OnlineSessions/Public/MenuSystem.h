// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem.generated.h"

/**
 * 
 */
UCLASS()
class ONLINESESSIONS_API UMenuSystem : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup();

protected:
	virtual bool Initialize() override;
	
private:
	
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();
	
	UFUNCTION()
	void JoinButtonClicked();

	//Subsystem designed to handle all online session functionality
	class UOnlineSessionsSubsystem* OnlineSessionsSubsystem;
};