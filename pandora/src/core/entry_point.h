#pragma once

#ifdef PANDORA_WINDOWS

	extern Pandora::Application* Pandora::CreateApplication();

	int main(int argc, char** argv)
	{
		Pandora::Log::Init();

		auto application = Pandora::CreateApplication();
		application->Run();
		delete application;
	}

#endif