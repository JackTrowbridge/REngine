#pragma once


#ifdef RENGINE_PLATFORM_WINDOWS

extern REngine::Application* REngine::CreateApplication();

int main(int arc, char** argv) {
	auto app = REngine::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error REngine only supports Windows
#endif
