#pragma once

#include "core.h"
#include "events/event.h"

namespace Pandora {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Heigth;

		WindowProps(
			const std::string& title = "Pandora Engine",
			unsigned int width = 1280, 
			unsigned int heigth = 920)
			: Title(title), Width(width), Heigth(heigth) { }
	};

	class PANDORA_API Window {
	public:
		virtual ~Window() {};

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual bool IsVSyncEnabled() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSyncEnabled(bool value) = 0;

		virtual void OnUpdate() = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}