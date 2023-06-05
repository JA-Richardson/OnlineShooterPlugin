// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineSessionsSubsystem.h"
#include "OnlineSubsystem.h"

UOnlineSessionsSubsystem::UOnlineSessionsSubsystem() : 
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &UOnlineSessionsSubsystem::OnCreateSessionComplete)),
	FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &UOnlineSessionsSubsystem::OnFindSessionsComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &UOnlineSessionsSubsystem::OnJoinSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &UOnlineSessionsSubsystem::OnDestroySessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &UOnlineSessionsSubsystem::OnStartSessionComplete))
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		SessionInterface = Subsystem->GetSessionInterface();
	}
}

void UOnlineSessionsSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
}

void UOnlineSessionsSubsystem::FindSession(int32 MaxSearchResults)
{
}

void UOnlineSessionsSubsystem::JoinSession(const FOnlineSessionSearchResult& SearchResult)
{
}

void UOnlineSessionsSubsystem::DestroySession()
{
}

void UOnlineSessionsSubsystem::StartSession()
{
}

void UOnlineSessionsSubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UOnlineSessionsSubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{
}

void UOnlineSessionsSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UOnlineSessionsSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UOnlineSessionsSubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
