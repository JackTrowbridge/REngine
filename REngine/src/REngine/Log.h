#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace REngine {
	class RENGINE_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define RENGINE_CORE_TRACE(...) ::REngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RENGINE_CORE_INFO(...) ::REngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RENGINE_CORE_WARN(...) ::REngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RENGINE_CORE_ERROR(...) ::REngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RENGINE_CORE_CRITICAL(...) ::REngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
 
// Client log macros
#define RENGINE_TRACE(...) ::REngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RENGINE_INFO(...) ::REngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define RENGINE_WARN(...) ::REngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RENGINE_ERROR(...) ::REngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define RENGINE_CRITICAL(...) ::REngine::Log::GetClientLogger()->critical(__VA_ARGS__)