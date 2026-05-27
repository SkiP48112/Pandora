#pragma once

#ifdef PANDORA_WINDOWS

	extern Pandora::Core::Application* Pandora::Core::CreateApplication();

	int main(int argc, char** argv)
	{
		auto application = Pandora::Core::CreateApplication();
		application->Run();
		delete application;
	}

#endif