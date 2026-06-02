#include "layer_stack.h"

namespace Pandora {

	LayerStack::LayerStack() 
	{
		m_LayerIter = begin();
	}

	LayerStack::~LayerStack() 
	{
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) 
	{
		m_Layers.insert(m_LayerIter, layer);
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer) 
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end()) {
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerIter--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end()) {
			overlay->OnDetach();
			m_Layers.erase(it);
		}
	}

}