#pragma once

#include "list.hpp"

namespace lispp{
	template <class>
	struct length{
	};
	template <class... Args>
	struct length<list<Args...>>{
		static constexpr int value = sizeof...(Args);
	};
}
