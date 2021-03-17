#pragma once

#include <SDL.h>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include "Result.hpp"

namespace jm
{
	class IoDevice
	{
	public:
	private:
	};

	enum class SdlOptions {
		None,
		Vulkan
	};

	class SdlIoDevice : public IoDevice
	{
	public:

		static std::unique_ptr<SdlIoDevice> create(SdlOptions options);


		bool run();

	private:
		/*
		*	Initializes an SDL2 IO Device
		*/
		SdlIoDevice(SdlOptions options);

		/*
		* Initialises the device instance
		*/
		void initialize();

		const SdlOptions m_options;
		SDL_Window* m_window{};
	};
}
