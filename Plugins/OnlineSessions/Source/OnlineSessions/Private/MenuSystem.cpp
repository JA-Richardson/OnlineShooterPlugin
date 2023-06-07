// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem.h"
#include "Components/Button.h"
#include "OnlineSessionsSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"


void UMenuSystem::MenuSetup(int32 NumConnections, FString TypeOfMatch)
{

	NumPublicConnections = NumConnections;
	MatchType = TypeOfMatch;
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // DoNotLock is default
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
	
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		OnlineSessionsSubsystem = GameInstance->GetSubsystem<UOnlineSessionsSubsystem>();
	}

	if (OnlineSessionsSubsystem)
	{
		OnlineSessionsSubsystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &UMenuSystem::OnCreateSession);
		OnlineSessionsSubsystem->MultiplayerOnFindSessionsComplete.AddUObject(this, &UMenuSystem::OnFindSession);
		OnlineSessionsSubsystem->MultiplayerOnJoinSessionComplete.AddUObject(this, &UMenuSystem::OnJoinSession);
		OnlineSessionsSubsystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &UMenuSystem::OnDestroySession);
		OnlineSessionsSubsystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &UMenuSystem::OnStartSession);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnlineSessionsSubsystem is null"));
	}
}

bool UMenuSystem::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	if (HostButton)
	{
		HostButton->OnClicked.AddDynamic(this, &UMenuSystem::HostButtonClicked);
	}
	if (JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this, &UMenuSystem::JoinButtonClicked);
	}
	return true;
}

void UMenuSystem::NativeDestruct()
{
	MenuTearDown();
	Super::NativeDestruct();
}

void UMenuSystem::OnCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Session Created Successfully"));
		}
		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel("/Game/ThirdPerson/Maps/Lobby?listen");
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Session Creation Failed"));
		}
	}
}

void UMenuSystem::OnFindSession(const TArray<FOnlineSessionSearchResult>& SearchResults, bool bWasSuccesful)
{
}

void UMenuSystem::OnJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
}

void UMenuSystem::OnDestroySession(bool bWasSuccessful)
{
}

void UMenuSystem::OnStartSession(bool bWasSuccessful)
{
}


void UMenuSystem::HostButtonClicked()
{
	

	if (OnlineSessionsSubsystem)
	{
		OnlineSessionsSubsystem->CreateSession(NumPublicConnections, MatchType);
		
	}
}

void UMenuSystem::JoinButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Join Button Clicked"));
	}
}

void UMenuSystem::MenuTearDown()
{
	RemoveFromParent();
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
			
		}
	}
}
