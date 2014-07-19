#pragma once

#include "list.hpp"
#include "int.hpp"

#include <type_traits>

namespace lispp{
	template <class Arg1, class Arg2>
	struct lt{
		static constexpr bool value = Arg1::type::value < Arg2::type::value;
		using type = typename std::conditional<value, t, nil>::type;
	};

	template <class Arg1, class Arg2>
	using lt_t = typename lt<Arg1, Arg2>::type;
}
