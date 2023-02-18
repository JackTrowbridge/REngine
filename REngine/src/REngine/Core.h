#pragma once

#ifdef RENGINE_PLATFORM_WINDOWS

	#ifdef RENGINE_BUILD_DLL
		#define RENGINE_API __declspec(dllexport)
	#else
		#define RENGINE_API __declspec(dllimport)
	#endif

#else
	#error REngine only supports Windows
#endif
