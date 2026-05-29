#pragma once

#include "event.h"

namespace Pandora {

	class PANDORA_API KeyEventBase : public Event {
		EVENT_CLASS_CATEGORY(EventCategory::KEYBOARD | EventCategory::INPUT)

	public:
		inline int GetKeyCode() { return m_KeyCode; }

	protected:
		KeyEventBase(int keyCode)
			: m_KeyCode(keyCode) {}

	protected:
		int m_KeyCode;
	};

	class PANDORA_API KeyPressedEvent : public KeyEventBase {
		EVENT_CLASS_TYPE(KEY_PRESSED)

	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEventBase(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << ": " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};

	class PANDORA_API KeyReleasedEvent : public KeyEventBase {
		EVENT_CLASS_TYPE(KEY_RELEASED)

	public:
		KeyReleasedEvent(int keyCode)
			: KeyEventBase(keyCode) {}

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << ": " << m_KeyCode;
			return ss.str();
		}
	};

}