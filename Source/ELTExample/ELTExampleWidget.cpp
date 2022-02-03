// Copyright (c) 2022 Damian Nowakowski. All rights reserved.

#include "ELTExampleWidget.h"
#include "ELT.h"

void UELTExampleWidget::NativeConstruct()
{
	Super::NativeConstruct();
	GetELT()->OnTextLocalizationChanged.AddDynamic(this, &UELTExampleWidget::TestOnLanguageChanged);
}

FString UELTExampleWidget::TestGetCurrentLanguage()
{
	return GetELT()->GetCurrentLanguage();
}

TArray<FString> UELTExampleWidget::TestGetAvailableLanguages()
{
	return GetELT()->GetAvailableLanguages();
}

bool UELTExampleWidget::TestCanSetLanguage(const FString& Lang)
{
	return GetELT()->CanSetLanguage(Lang);
}

bool UELTExampleWidget::TestSetLanguage(const FString& Lang)
{
	return GetELT()->SetLanguage(Lang);
}

void UELTExampleWidget::TestOnLanguageChanged()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Locs changed to (CPP): %s"), *TestGetCurrentLanguage()));
}

