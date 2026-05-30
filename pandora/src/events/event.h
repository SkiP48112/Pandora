#pragma once

#include "core/core.h"

namespace Pandora {

	enum class EventType {
		NONE = 0,
		KEY_PRESSED, KEY_RELEASED,
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED,
		WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
		APP_TICK, APP_RENDER, APP_UPDATE
	};

	enum EventCategory {
		NONE			= 0,
		KEYBOARD		= BIT(0),
		MOUSE			= BIT(1),
		MOUSE_BUTTON	= BIT(2),
		INPUT			= BIT(3),
		APPLICATION		= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)														\
		public:																		\
			static EventType GetStaticType() { return EventType::type ; }			\
			virtual EventType GetType() const override { return GetStaticType(); }	\
			virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)												\
		public:																		\
			virtual int GetCategoryFlags() const override { return category; }

	class PANDORA_API Event {
	public:
		~Event() = default;

		virtual EventType GetType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(int category) 
		{
			return GetCategoryFlags() & category;
		}

	public:
		bool IsHandled = false;
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T, typename F>
		bool Dispatch(const F& func) 
		{
			if (m_Event.GetType() == T::GetStaticType()) {
				m_Event.IsHandled = func(static_cast<T&>(m_Event));
				return true;
			}

			return false;
		} 

	private:
		Event& m_Event;
	};

	using EventCallbackFn = std::function<void(Event&)>;

	inline std::string format_as(const Event& e) 
	{
		return e.ToString();
	}
}