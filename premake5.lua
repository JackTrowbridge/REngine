workspace "REngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "REngine"
	location "REngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- WARNING: .hpp and .c files may be used in the future.
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RENGINE_PLATFORM_WINDOWS",
			"RENGINE_BUILD_DLL"
		}
 
		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- WARNING: .hpp and .c files may be used in the future.
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"REngine/vendor/spdlog/include",
		"REngine/src"
	}

	links{
		"REngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RENGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RENGINE_DIST"
		optimize "On"

