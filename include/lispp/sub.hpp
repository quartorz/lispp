#pragma once

#include "list.hpp"

namespace lispp{
	template <class... Args>
	struct sub{
		static constexpr int value = 0;
		using type = int_<value>;
	};
	template <class Arg, class... Args>
	struct sub<Arg, Args...>{
		static constexpr int value = Arg::type::value - sub<Args...>::value;
		using type = int_<value>;
	};

	template <class... Args>
	using sub_t = typename sub<Args...>::type;
}
