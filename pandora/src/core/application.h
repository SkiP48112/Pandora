#pragma once

#include "core.h"
#include "window.h"

namespace Pandora {

	class PANDORA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	// NOTE: To be defined in the CLIENT
	Application* CreateApplication();

}