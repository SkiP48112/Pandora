#include "layer_stack.h"

namespace Pandora {

	LayerStack::LayerStack() 
	{
	}

	LayerStack::~LayerStack() 
	{
		for (Layer* layer : m_Layers) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) 
	{
		m_Layers.emplace(begin() + m_LayerIndex, layer);
		m_LayerIndex++;

		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer) 
	{
		auto it = std::find(begin(), begin() + m_LayerIndex, layer);
		if (it != m_Layers.begin() + m_LayerIndex) {
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerIndex--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end()) {
			overlay->OnDetach();
			m_Layers.erase(it);
		}
	}

}