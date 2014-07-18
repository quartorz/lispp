#pragma once

#include "list.hpp"

namespace lispp{
	template <class... Args>
	struct add{
		static constexpr int value = 0;
		using type = int_<value>;
	};
	template <class Arg, class... Args>
	struct add<Arg, Args...>{
		static constexpr int value = Arg::type::value + add<Args...>::value;
		using type = int_<value>;
	};
}
