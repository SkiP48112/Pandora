#include "pandora.h"

class SandboxLayer : public Pandora::Layer {
public:
	SandboxLayer() 
		: Layer("Sandbox") {}

	void OnUpdate() override
	{
		PANDORA_INFO("{0}: OnUpdate", GetName());
	}

	void OnEvent(Pandora::Event& event) override
	{
		PANDORA_INFO("{0}: OnEvent {1}", GetName(), event);
	}
};

class Sandbox : public Pandora::Application {
public:
	Sandbox()
	{
		PushLayer(new SandboxLayer());
		PushLayer(new Pandora::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Pandora::Application* Pandora::CreateApplication() 
{
	return new Sandbox();
}