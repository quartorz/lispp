#pragma once

#include "list.hpp"

namespace lispp{
	template <class... Args>
	struct div{
		static constexpr int value = 1;
		using type = int_<value>;
	};
	template <class Arg, class... Args>
	struct div<Arg, Args...>{
		static constexpr int value = Arg::type::value / div<Args...>::value;
		using type = int_<value>;
	};
}
