#pragma once

#include "list.hpp"

namespace lispp{
	template <template <class...> class Func, class List>
	struct apply{
	};
	template <template <class...> class Func, class... Args>
	struct apply<Func, list<Args...>>{
		using type = typename Func<Args...>::type;
	};

	template <template <class...> class Func, class List>
	using apply_t = typename apply<Func, List>::type;
}
