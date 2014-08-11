#pragma once

#include "base_types.hpp"

namespace lispp{
	class apply{
		template <class Func, class List>
		class i : public i<Func, typename List::template type<>>{
		};
		template <class Func, class... Elems>
		class i<Func, list::type<Elems...>>{
		public:
			template <class...>
			using type = typename Func::template type<Elems...>;
		};
	public:
		template <class Func, class List>
		using type = i<Func, List>;
	};
	template <class Func, class List>
	using apply_t = apply::type<Func, List>;
}
