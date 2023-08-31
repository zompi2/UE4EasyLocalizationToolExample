// Copyright (c) 2023 Damian Nowakowski. All rights reserved.

#include "ELTExampleWidget.h"
#include "ELT.h"

void UELTExampleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GetELT()->OnTextLocalizationChanged.AddDynamic(this, &UELTExampleWidget::TestOnLanguageChangedDynamic);
	OnChangeHandle = GetELT()->OnTextLocalizationChangedStatic.AddLambda([this]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Locs changed to (CPP Static): %s"), *TestGetCurrentLanguage()));
	});
}

void UELTExampleWidget::NativeDestruct()
{
	GetELT()->OnTextLocalizationChanged.RemoveDynamic(this, &UELTExampleWidget::TestOnLanguageChangedDynamic);
	GetELT()->OnTextLocalizationChangedStatic.Remove(OnChangeHandle);

	Super::NativeDestruct();
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

void UELTExampleWidget::TestOnLanguageChangedDynamic()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Locs changed to (CPP Dynamic): %s"), *TestGetCurrentLanguage()));
}

