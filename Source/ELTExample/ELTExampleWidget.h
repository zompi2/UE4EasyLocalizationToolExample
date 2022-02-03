// Copyright (c) 2022 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ELTExampleWidget.generated.h"

UCLASS()
class ELTEXAMPLE_API UELTExampleWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void NativeConstruct() override;

	UFUNCTION(BlueprintPure)
	FString TestGetCurrentLanguage();

	UFUNCTION(BlueprintPure)
	TArray<FString> TestGetAvailableLanguages();

	UFUNCTION(BlueprintPure)
	bool TestCanSetLanguage(const FString& Lang);

	UFUNCTION(BlueprintCallable)
	bool TestSetLanguage(const FString& Lang);

	UFUNCTION()
	void TestOnLanguageChanged();
};
