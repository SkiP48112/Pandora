#pragma once

#include "core.h"

namespace Pandora {

	class PANDORA_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		void Run();
	};

	// NOTE: To be defined in the CLIENT
	Application* CreateApplication();

}