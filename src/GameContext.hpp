#pragma once

#include "types.hpp"
#include "Result.hpp"
#include <string>

namespace jm
{
	class SdlIoDevice;

	class GameContext
	{
	public:
		static Uniq<GameContext> createInstance();

		void run();

	private:
		void initialize();
		Uniq<SdlIoDevice> m_ioDevice;
	};
}