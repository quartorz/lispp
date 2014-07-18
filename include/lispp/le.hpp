#pragma once

#include "list.hpp"
#include "int.hpp"

#include <type_traits>

namespace lispp{
	template <class Arg1, class Arg2>
	struct le{
		static constexpr bool value = Arg1::type::value <= Arg2::type::value;
		using type = typename std::conditional<value, t, nil>::type;
	};
}
