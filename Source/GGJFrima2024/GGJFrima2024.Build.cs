// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GGJFrima2024 : ModuleRules
{
	public GGJFrima2024(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MounteaDialogueSystem" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "MounteaDialogueSystem" });
	}
}
