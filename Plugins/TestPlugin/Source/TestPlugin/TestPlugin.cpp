// Copyright (c) 2026 Damian Nowakowski. All rights reserved.

#include "Modules/ModuleManager.h"

class TESTPLUGIN_API FTestPlugin : public IModuleInterface
{};

IMPLEMENT_MODULE(FTestPlugin, TestPlugin)