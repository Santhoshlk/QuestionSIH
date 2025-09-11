// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GyaanPathProt : ModuleRules
{
	public GyaanPathProt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "EnhancedInput","UMG"});

		PublicIncludePaths.AddRange(new string[] {
			"GyaanPathProt",
			"GyaanPathProt/Variant_Platforming",
			"GyaanPathProt/Variant_Platforming/Animation",
			"GyaanPathProt/Variant_Combat",
			"GyaanPathProt/Variant_Combat/AI",
			"GyaanPathProt/Variant_Combat/Animation",
			"GyaanPathProt/Variant_Combat/Gameplay",
			"GyaanPathProt/Variant_Combat/Interfaces",
			"GyaanPathProt/Variant_Combat/UI",
			"GyaanPathProt/Variant_SideScrolling",
			"GyaanPathProt/Variant_SideScrolling/AI",
			"GyaanPathProt/Variant_SideScrolling/Gameplay",
			"GyaanPathProt/Variant_SideScrolling/Interfaces",
			"GyaanPathProt/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
