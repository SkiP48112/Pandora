#pragma once

#ifdef PANDORA_WINDOWS

	extern Pandora::Application* Pandora::CreateApplication();

	int main(int argc, char** argv)
	{
		Pandora::Log::Init();

		PANDORA_CORE_TRACE("Trace");
		PANDORA_CORE_INFO("Info");
		PANDORA_CORE_DEBUG("Debug");
		PANDORA_CORE_WARN("Warn");
		PANDORA_CORE_ERROR("Error");
		PANDORA_CORE_CRITICAL("Critical");

		PANDORA_TRACE("Trace");
		PANDORA_INFO("Info");
		PANDORA_DEBUG("Debug");
		PANDORA_WARN("Warn");
		PANDORA_ERROR("Error");
		PANDORA_CRITICAL("Critical");

		auto application = Pandora::CreateApplication();
		application->Run();
		delete application;
	}

#endif