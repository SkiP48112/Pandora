#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "core.h"

namespace Pandora {

	class PANDORA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define PANDORA_CORE_TRACE(...)    Pandora::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PANDORA_CORE_INFO(...)     Pandora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PANDORA_CORE_DEBUG(...)    Pandora::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define PANDORA_CORE_WARN(...)     Pandora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PANDORA_CORE_ERROR(...)	   Pandora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PANDORA_CORE_CRITICAL(...) Pandora::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define PANDORA_TRACE(...)         Pandora::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PANDORA_INFO(...)          Pandora::Log::GetClientLogger()->info(__VA_ARGS__)
#define PANDORA_DEBUG(...)         Pandora::Log::GetClientLogger()->debug(__VA_ARGS__)
#define PANDORA_WARN(...)          Pandora::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PANDORA_ERROR(...)         Pandora::Log::GetClientLogger()->error(__VA_ARGS__)
#define PANDORA_CRITICAL(...)      Pandora::Log::GetClientLogger()->critical(__VA_ARGS__)