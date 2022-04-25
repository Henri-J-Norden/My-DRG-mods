#pragma once
#include "CoreMinimal.h"
#include "DeepCSGNode.h"
#include "DeepCSGFloatPlane.h"
#include "DeepCSGFloatTree.generated.h"

USTRUCT(BlueprintType)
struct FDeepCSGFloatTree {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FDeepCSGNode Root;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FDeepCSGFloatPlane> planes;
    
    FSDENGINE_API FDeepCSGFloatTree();
};
