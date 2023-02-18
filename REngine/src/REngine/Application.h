#pragma once

#include "Core.h"

namespace REngine {

	class RENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be def in client
	Application* CreateApplication();

}
