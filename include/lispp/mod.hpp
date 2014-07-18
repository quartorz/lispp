#pragma once

#include "list.hpp"

namespace lispp{
	template <class... Args>
	struct mod{
		static constexpr int value = 1;
		using type = int_<value>;
	};
	template <class Arg, class... Args>
	struct mod<Arg, Args...>{
		static constexpr int value = Arg::type::value % mod<Args...>::value;
		using type = int_<value>;
	};
}
