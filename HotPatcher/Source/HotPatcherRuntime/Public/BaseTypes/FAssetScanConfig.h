#pragma once
// project header
#include "FPatcherSpecifyAsset.h"
#include "FExternFileInfo.h"
#include "ETargetPlatform.h"
#include "FPlatformExternFiles.h"
#include "FPlatformExternAssets.h"

// engine header
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "FAssetScanConfig.generated.h"

USTRUCT(BlueprintType)
struct HOTPATCHERRUNTIME_API FAssetScanConfig
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
	bool bPackageTracker = true;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (RelativeToGameContentDir, LongPackageName), Category="")
    TArray<FDirectoryPath> AssetIncludeFilters;
    // Ignore directories in AssetIncludeFilters 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RelativeToGameContentDir, LongPackageName), Category="")
    TArray<FDirectoryPath> AssetIgnoreFilters;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    bool bIncludeHasRefAssetsOnly = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    bool bAnalysisFilterDependencies=true;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    TArray<EAssetRegistryDependencyTypeEx> AssetRegistryDependencyTypes;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    TArray<FPatcherSpecifyAsset> IncludeSpecifyAssets;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    bool bRecursiveWidgetTree = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
	bool bSupportWorldComposition = true;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="")
    bool bForceSkipContent = true;
    // force exclude asset folder e.g. Exclude editor content when cooking in Project Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (RelativeToGameContentDir, LongPackageName, EditCondition="bForceSkipContent"), Category="")
    TArray<FDirectoryPath> ForceSkipContentRules;
    UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (EditCondition="bForceSkipContent"), Category="")
    TArray<FSoftObjectPath> ForceSkipAssets;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition="bForceSkipContent"), Category="")
    TArray<UClass*> ForceSkipClasses;

};
