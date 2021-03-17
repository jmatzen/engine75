#include "GameContext.hpp"
#include "SdlIoDevice.hpp"
#include <pdqlog.hpp>
#include <thread>
#include <chrono>

using namespace jm;

Uniq<GameContext> GameContext::createInstance()
{
	auto context = Uniq<GameContext>(new GameContext());
	context->initialize();
	return context;
}

void GameContext::initialize() {
	m_ioDevice = SdlIoDevice::create(SdlOptions::Vulkan);
	if (!m_ioDevice)
		throw std::runtime_error("failed to initialize SdlIoDevice");
}

void GameContext::run() {

	while (m_ioDevice->run()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

}