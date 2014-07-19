#pragma once

#include "list.hpp"
#include "int.hpp"

namespace lispp{
	template <class>
	struct length{
	};
	template <class... Args>
	struct length<list<Args...>>{
		static constexpr int value = sizeof...(Args);
		using type = int_<value>;
	};

	template <class List>
	using length_t = typename length<List>::type;
}
