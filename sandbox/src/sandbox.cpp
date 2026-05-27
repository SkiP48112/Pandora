#include "pandora.h"

class Sandbox : public Pandora::Core::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};


Pandora::Core::Application* Pandora::Core::CreateApplication() 
{
	return new Sandbox();
}