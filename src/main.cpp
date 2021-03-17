#include <pdqlog.hpp>
#include <fmt/format.h>
#include "SdlIoDevice.hpp"
#include "GameContext.hpp"

using namespace jm;

int main(int argc, const char** argv)
{
	pdqlog::set_callback([](const pdqlog::LogCallbackData& logdata) {
		fmt::print("{:12.6f} {:5} {}\n", logdata.time, logdata.level, logdata.message);
		});


	auto gameContext = GameContext::createInstance();
	gameContext->run();

}

 