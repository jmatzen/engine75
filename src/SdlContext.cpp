#include "SdlIoDevice.hpp"
#include "types.hpp"
#include <pdqlog.hpp>

using namespace jm;

SdlIoDevice::SdlIoDevice(SdlOptions options) 
	: m_options(options)
{

}

Uniq<SdlIoDevice> SdlIoDevice::create(SdlOptions options) {
	auto instance = std::unique_ptr<SdlIoDevice>(new SdlIoDevice(options));
	instance->initialize();
	return std::move(instance);
}

void SdlIoDevice::initialize() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		throwException("SDL_Init failed: {}", SDL_GetError());
	}

	if (m_options != SdlOptions::Vulkan) {
		throwException("no valid graphics options");
	}

	u32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN;

	m_window = SDL_CreateWindow("game"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, 1024
		, 768
		, flags)
		;

	if (!m_window) {
		PDQLOG_FATAL("unable to create SDL window {}", SDL_GetError());
		throwException("unable to create SDL window: ", SDL_GetError());
	}

}

bool SdlIoDevice::run() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT: return false;

		}
	}
	return true;
}