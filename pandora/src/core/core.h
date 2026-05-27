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