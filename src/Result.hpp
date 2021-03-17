#pragma once

#include <concepts>

namespace jm
{
	template<std::move_constructible T, std::move_constructible E>
	struct Result {
		using error_type = E;
		using value_type = T;

		enum class Tag {
			ok, error
		} tag;
		union {
			T ok_;
			E err_;
		};

		Result(E&& e)
			: tag(Tag::error)
		{
			new(&err_)E(std::forward<E>(e));
		}

		Result(T&& val)
			: tag(Tag::ok)
		{
			new(&ok_)T(std::forward<T>(val));
		}

		~Result() {
			switch (tag) {
			case Tag::ok: ok_.~T(); break;
			case Tag::error: err_.~E(); break;
			}
		}

		bool isErr() const { return tag == Tag::error; }

		bool isOk() const { return tag == Tag::ok; }

		const E& err() const { return err_; }

		const T& ok() const { return ok_; }

	private:
		Result(Result&);
		void operator=(Result&);
	};
}