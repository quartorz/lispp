#pragma once

#include "list.hpp"

namespace lispp{
	namespace aux_{
		template <class, class, class = void>
		struct c_or_impl{
		};
		template <class... Args, class T>
		struct c_or_impl<list<Args...>, T, void>{
			using type = t;
		};
		template <class... Args>
		struct c_or_impl<list<Args...>, nil, typename std::enable_if<sizeof...(Args) != 0>::type>
			: c_or_impl<cdr_t<list<Args...>>, typename car_t<cdr_t<list<Args...>>>::type>
		{
		};
		template <class... Args>
		struct c_or_impl<list<Args...>, nil, typename std::enable_if<sizeof...(Args) == 0>::type>
			: c_or_impl<cdr_t<list<Args...>>, typename car_t<cdr_t<list<Args...>>>::type>
		{
			using type = nil;
		};
	}

	template <class>
	struct c_or{
	};
	template <class... Args>
	struct c_or<list<Args...>> : aux_::c_or_impl<list<Args...>, typename car_t<list<Args...>>::type>{
	};
}
