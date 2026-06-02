#pragma once

#include "core.h"
#include "events/event.h"

namespace Pandora {

	class PANDORA_API Layer {
	public:
		Layer(const std::string& name = "Empty Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};

}