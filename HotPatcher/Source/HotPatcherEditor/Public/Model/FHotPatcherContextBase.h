#pragma once

#include "CoreMinimal.h"
#include "Templates/HotPatcherTemplateHelper.hpp"

#define CREATE_ACTION_WIDGET_LAMBDA(WIDGET_CLASS,MODENAME) \
	[](TSharedPtr<FHotPatcherContextBase> InContext)->TSharedRef<SCompoundWidget>{\
		return SNew(WIDGET_CLASS,InContext).Visibility_Lambda([=]()->EVisibility{\
			return InContext->GetModeName().IsEqual(MODENAME) ? EVisibility::Visible : EVisibility::Collapsed;\
	});}

struct HOTPATCHEREDITOR_API FHotPatcherContextBase
{
public:
	FHotPatcherContextBase()=default;
	virtual ~FHotPatcherContextBase(){}
	virtual FName GetContextName()const{ return TEXT(""); }

	FORCEINLINE_DEBUGGABLE virtual void SetModeByName(FName InPatcherModeName){}
	FORCEINLINE_DEBUGGABLE virtual FName GetModeName(){ return TEXT(""); }
		
};