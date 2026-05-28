#pragma once

#include "event.h"

namespace Pandora {

	class PANDORA_API WindowCloseEvent : public Event 
	{
		EVENT_CLASS_TYPE(WINDOW_CLOSE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		WindowCloseEvent() = default;
	};

	class PANDORA_API WindowFocusEvent : public Event
	{
		EVENT_CLASS_TYPE(WINDOW_FOCUS)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		WindowFocusEvent() = default;
	};

	class PANDORA_API WindowLostFocusEvent : public Event
	{
		EVENT_CLASS_TYPE(WINDOW_LOST_FOCUS)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		WindowLostFocusEvent() = default;
	};

	class PANDORA_API WindowResizeEvent : public Event
	{
		EVENT_CLASS_TYPE(WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << GetName() << ": (" << m_Width << ":" << m_Height << ")";
			return ss.str();
		}

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class PANDORA_API WindowMovedEvent : public Event
	{
		EVENT_CLASS_TYPE(WINDOW_MOVED)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		WindowMovedEvent(int positionX, int positionY)
			: m_PositionX(positionX), m_PositionY(positionY) {}

		inline int GetX() const { return m_PositionX; }
		inline int GetY() const { return m_PositionY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << GetName() << ": (" << m_PositionX << ":" << m_PositionY << ")";
			return ss.str();
		}

	private:
		int m_PositionX;
		int m_PositionY;
	};

}