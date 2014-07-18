#pragma once

#include "list.hpp"

namespace lispp{
	template <bool, class>
	struct cond_impl{
	};
	template <class Head, class... Rest>
	struct cond_impl<true, list<Head, Rest...>>{
		using type = car_t<cdr_t<Head>>;
	};

	template <class Head, class... Rest>
	struct cond_impl<false, list<Head, Rest...>>
		: cond_impl<
			!null<typename car_t<car_t<list<Rest...>>>::type>::value
			, list<Rest...>>
	{
	};

	template <class... Args>
	struct cond : cond_impl<!null<typename car_t<car_t<list<Args...>>>::type>::value, list<Args...>>{
	};

	template <class... Args>
	using cond_t = typename cond<Args...>::type;
}
