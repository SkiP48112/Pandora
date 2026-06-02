#pragma once

#ifdef PANDORA_WINDOWS
	#ifdef PANDORA_BUILD_DLL
		#define PANDORA_API __declspec(dllexport)
	#else
		#define PANDORA_API __declspec(dllimport)
	#endif
#else
	#error Pandora Engine does not yet support your platform
#endif

#ifdef PANDORA_ENABLE_ASSERTS
	#define PANDORA_ASSERT(x, ...) { if(!(x)) { PANDORA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PANDORA_CORE_ASSERT(x, ...) { if(!(x)) { PANDORA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PANDORA_ASSERT(x, ...)
	#define PANDORA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (x << 1)

#define PANDORA_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)