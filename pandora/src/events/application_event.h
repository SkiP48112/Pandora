#pragma once

#include "event.h"

namespace Pandora {

	class PANDORA_API AppTickEvent : public Event
	{
		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		AppTickEvent() = default;
	};

	class PANDORA_API AppRenderEvent : public Event
	{
		EVENT_CLASS_TYPE(APP_RENDER)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		AppRenderEvent() = default;
	};

	class PANDORA_API AppUpdateEvent : public Event
	{
		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)

	public:
		AppUpdateEvent() = default;
	};

}