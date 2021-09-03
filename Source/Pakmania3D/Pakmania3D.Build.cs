// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Pakmania3D : ModuleRules
{
	public Pakmania3D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
