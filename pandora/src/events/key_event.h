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
		KeyPressedEvent(int keyCode, bool isRepeated)
			: KeyEventBase(keyCode), m_IsRepeated(isRepeated) {}

		inline bool IsRepeated() const { return m_IsRepeated; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << ": " << m_KeyCode << "";
			if (IsRepeated()) {
				ss << ": Repeated";
			}

			return ss.str();
		}

	private:
		bool m_IsRepeated;
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