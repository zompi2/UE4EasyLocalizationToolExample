// Copyright (c) 2026 Damian Nowakowski. All rights reserved.

using System.IO;
using UnrealBuildTool;

public class TestPlugin : ModuleRules
{
	public TestPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine"
			}
		);

        string SourceFolder = Path.Combine(ModuleDirectory, "..", "..", "Content", "Localization");       
        if (Directory.Exists(SourceFolder))
        {
            foreach (string FilePath in Directory.EnumerateFiles(SourceFolder, "*", SearchOption.AllDirectories))
            {
                RuntimeDependencies.Add(FilePath, StagedFileType.NonUFS);
            }
        }
    }
}
