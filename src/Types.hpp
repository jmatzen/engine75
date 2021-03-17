#include <cstdint>
#include <memory>
#include <optional>
#include <fmt/format.h>
#include <string>

namespace jm
{
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;
	using s8 = int8_t;
	using s16 = int16_t;
	using s32 = int32_t;
	using s64 = int64_t;
}


namespace jm
{
	template<typename T>
	using Rc = std::shared_ptr<T>;

	template<typename T>
	using Weak = std::weak_ptr<T>;

	template<typename T>
	using Uniq = std::unique_ptr<T>;

	template<typename T>
	using Opt = std::optional<T>;

	template<typename T = std::runtime_error, typename...A>
	[[noreturn]]
	void throwException(A&& ... a)
	{
#if defined _MSC_VER
		__debugbreak();
#endif
		std::string err = fmt::format(std::forward<A>(a)...).c_str();
		throw T(err.c_str());
	}
}