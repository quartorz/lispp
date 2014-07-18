#pragma once

#include "list.hpp"
#include "print.hpp"
namespace lispp{
	namespace aux_{
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
	}

	template <class List>
	struct cond : aux_::cond_impl<!null<typename car_t<car_t<List>>::type>::value, List>{
	};

	template <class List>
	using cond_t = typename cond<List>::type;
}
