#pragma once

#include "list.hpp"

namespace lispp{
	template <class... Args>
	struct mul{
		static constexpr int value = 1;
		using type = int_<value>;
	};
	template <class Arg, class... Args>
	struct mul<Arg, Args...>{
		static constexpr int value = Arg::type::value * mul<Args...>::value;
		using type = int_<value>;
	};

	template <class... Args>
	using mul_t = typename mul<Args...>::type;
}
