#pragma once

#include "base_types.hpp"

namespace lispp{
	class append{
		template <class... Lists>
		class i{
		public:
			template <class...>
			using type = nil;
		};
		template <class Type, class... Lists>
		class i<Type, Lists...> : public i<typename Type::template type<>, Lists...>{
		};
		template <class... Elems>
		class i<list::type<Elems...>>{
		public:
			template <class...>
			using type = list::type<Elems...>;
		};
		template <class... Elems, class Type, class... Lists>
		class i<list::type<Elems...>, Type, Lists...> :
			public i<list::type<Elems...>, typename Type::template type<>, Lists...>{
		};
		template <class... Elems1, class... Elems2, class... Lists>
		class i<list::type<Elems1...>, list::type<Elems2...>, Lists...> :
			public i<list::type<Elems1..., Elems2...>, Lists...>{
		};
	public:
		template <class... Lists>
		using type = i<Lists...>;
	};
	template <class... Lists>
	using append_t = append::type<Lists...>;
}
