using UnrealBuildTool;

public class Emberfall : ModuleRules
{
    public Emberfall(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "EnhancedInput",
            "GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "AIModule",
            "GameplayAbilities",
            "GameplayTasks",
            "Slate",
            "SlateCore",
            "UMG"
        });
    }
}

