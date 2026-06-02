#pragma once

#include "core.h"
#include "window.h"
#include "events/window_event.h"
#include "layer_stack.h"

namespace Pandora {

	class PANDORA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
		Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_IsRunning = true;
	};

	// NOTE: To be defined in the CLIENT
	Application* CreateApplication();

}