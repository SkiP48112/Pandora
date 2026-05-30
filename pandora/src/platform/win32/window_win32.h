#pragma once

#include <GLFW/glfw3.h>
#include "core/window.h"

namespace Pandora {

	struct WindowDataWin32 {
		std::string Title;
		unsigned int Width;
		unsigned int Heigth;
		bool IsVSyncEnabled;

		EventCallbackFn EventCallback;
	};

	class PANDORA_API WindowWin32 : public Window {
	public:
		WindowWin32(const WindowProps& props);
		virtual ~WindowWin32();

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Heigth; }
		inline bool IsVSyncEnabled() const override { return m_Data.IsVSyncEnabled; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSyncEnabled(bool value) override;

		virtual void OnUpdate() override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Terminate();

	private:
		GLFWwindow* m_Window;
		WindowDataWin32 m_Data;
	};

}