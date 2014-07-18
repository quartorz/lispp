#pragma once

#include "list.hpp"
#include "length.hpp"
#include "or.hpp"

namespace lispp{
	namespace aux_{
		template <bool, template <class...> class Func, class... Args>
		struct maplist_impl
			 : cons_t<
				typename Func<Args...>::type
				, typename maplist_impl<
					!or_impl(!length<cdr_t<Args>>::value...)
					, Func
					, cdr_t<Args>...
				>::type
			>
		{
		};
		template <template <class...> class Func, class... Args>
		struct maplist_impl<false, Func, Args...>
		{
			using type = list<>;
		};
	}

	template <template <class...> class Func, class... Lists>
	struct maplist : aux_::maplist_impl<!aux_::or_impl(!length<Lists>::value...), Func, Lists...>
	{
	};

	template <template <class...> class Func, class... Lists>
	using maplist_t = typename maplist<Func, Lists...>::type;
}
