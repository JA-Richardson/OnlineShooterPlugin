// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
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
		void MenuSetup(int32 NumConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby?listen")), FString GamePath = FString(TEXT("/Game/ThirdPerson/Maps/Arena?listen")));

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* HostButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* JoinButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartButton;

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	//
	//Callbacks for custom delegates in UOnlineSessionsSubsystem
	//
	UFUNCTION()
		void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SearchResults, bool bWasSuccesful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
		void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
		void OnStartSession(bool bWasSuccessful);

private:

	

	UFUNCTION()
		void HostButtonClicked();

	UFUNCTION()
		void JoinButtonClicked();
	UFUNCTION()
		void StartButtonClicked();

	void MenuTearDown();

	//Subsystem designed to handle all online session functionality
	class UOnlineSessionsSubsystem* OnlineSessionsSubsystem;

	int32 NumPublicConnections{ 4 };
	FString MatchType{ TEXT("FreeForAll") };
	FString PathToLobby{ TEXT("") };
	FString PathToGameMap = { TEXT("") };
	
};