#pragma once

#include "event.h"
#include "core/mouse_codes.h"

namespace Pandora {

	class PANDORA_API MouseButtonEventBase : public Event {
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::MOUSE_BUTTON | EventCategory::INPUT)
	
	public:
		inline MouseCode GetKeyCode() { return m_KeyCode; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << ": " << m_KeyCode;
			return ss.str();
		}

	protected:
		MouseButtonEventBase(MouseCode keyCode)
			: m_KeyCode(keyCode) {}

	protected:
		MouseCode m_KeyCode;
	};

	class PANDORA_API MouseButtonPressedEvent : public MouseButtonEventBase {
		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	
	public:
		MouseButtonPressedEvent(MouseCode keyCode)
			: MouseButtonEventBase(keyCode) {}
	};

	class PANDORA_API MouseButtonReleasedEvent : public MouseButtonEventBase {
		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)

	public:
		MouseButtonReleasedEvent(MouseCode keyCode)
			: MouseButtonEventBase(keyCode) {}
	};

	class PANDORA_API MouseMovedEvent : public Event {
		EVENT_CLASS_TYPE(MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::INPUT)

	public:
		MouseMovedEvent(const float mouseX, const float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << GetName() << ": (" << m_MouseX << ":" << m_MouseY << ")";
			return ss.str();
		}

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class PANDORA_API MouseScrolledEvent : public Event {
		EVENT_CLASS_TYPE(MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EventCategory::MOUSE | EventCategory::INPUT)

	public:
		MouseScrolledEvent(const float offsetX, const float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << GetName() << ": (" << m_OffsetX << ":" << m_OffsetY << ")";
			return ss.str();
		}

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

}