#pragma once

#include "event.h"

namespace Pandora {

	class PANDORA_API MouseButtonEventBase : public Event {
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::MOUSE_BUTTON | EventCategory::INPUT)
	
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << ": " << m_KeyCode;
			return ss.str();
		}

	protected:
		MouseButtonEventBase(int keyCode)
			: m_KeyCode(keyCode) {}

	protected:
		int m_KeyCode;
	};

	class PANDORA_API MouseButtonPressedEvent : public MouseButtonEventBase {
		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	
	public:
		MouseButtonPressedEvent(int keyCode)
			: MouseButtonEventBase(keyCode) {}
	};

	class PANDORA_API MouseButtonReleasedEvent : public MouseButtonEventBase {
		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)

	public:
		MouseButtonReleasedEvent(int keyCode)
			: MouseButtonEventBase(keyCode) {}
	};

	class PANDORA_API MouseMovedEvent : public Event {
		EVENT_CLASS_TYPE(MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::INPUT)

	public:
		MouseMovedEvent(int mouseX, int mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline int GetX() const { return m_MouseX; }
		inline int GetY() const { return m_MouseY; }

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << GetName() << ": (" << m_MouseX << ":" << m_MouseY << ")";
			return ss.str();
		}

	private:
		int m_MouseX;
		int m_MouseY;
	};

	class PANDORA_API MouseScrolledEvent : public Event {
		EVENT_CLASS_TYPE(MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::INPUT)

	public:
		MouseScrolledEvent(int offsetX, int offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline int GetOffsetX() const { return m_OffsetX; }
		inline int GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << GetName() << ": (" << m_OffsetX << ":" << m_OffsetY << ")";
			return ss.str();
		}

	private:
		int m_OffsetX;
		int m_OffsetY;
	};

}