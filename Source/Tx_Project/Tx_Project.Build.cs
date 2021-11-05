// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tx_Project : ModuleRules
{
	public Tx_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
