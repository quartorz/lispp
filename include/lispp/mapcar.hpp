#pragma once

#include "list.hpp"
#include "length.hpp"
#include "or.hpp"

namespace lispp{
	namespace aux_{
		template <bool, template <class...> class Func, class... Args>
			struct mapcar_impl
			 : cons_t<
				typename Func<car_t<Args>...>::type
				, typename mapcar_impl<
					!or_impl(!length<cdr_t<Args>>::value...)
					, Func
					, cdr_t<Args>...
				>::type
			>
		{
		};
		template <template <class...> class Func, class... Args>
		struct mapcar_impl<false, Func, Args...>
		{
			using type = list<>;
		};
	}

	template <template <class...> class Func, class... Lists>
	struct mapcar : aux_::mapcar_impl<!aux_::or_impl(!length<Lists>::value...), Func, Lists...>
	{
	};

	template <template <class...> class Func, class... Lists>
	using mapcar_t = typename mapcar<Func, Lists...>::type;
}
