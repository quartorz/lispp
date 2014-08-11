#pragma once

#include <type_traits>

#include "base_types.hpp"

namespace lispp{
	class null{
		template <class Type>
		class i{
		public:
			static constexpr bool value = std::is_same<typename Type::template type<>, nil>::value;
			template <class...>
			using type = typename std::conditional<value, t, nil>::type;
		};
	public:
		template <class Type>
		using type = i<Type>;
	};
	template <class Type>
	using null_t = null::type<Type>;

	class car{
		template <class Type>
		class i : public i<typename Type::template type<>>{
		};
		template <class Head, class... Rest>
		class i<list::type<Head, Rest...>>{
		public:
			template <class...>
			using type = typename Head::template type<>;
		};
	public:
		template <class Type>
		using type = i<Type>;
	};
	template <class Type>
	using car_t = car::type<Type>;

	class cdr{
		template <class Type>
		class i : public i<typename Type::template type<>>{
		};
		template <class Head, class... Rest>
		class i<list::type<Head, Rest...>>{
		public:
			template <class...>
			using type = list::type<Rest...>;
		};
	public:
		template <class Type>
		using type = i<Type>;
	};
	template <class Type>
	using cdr_t = cdr::type<Type>;

	class cons{
		template <class Type, class List>
		class i : public i<Type, typename List::template type<>>{
		};
		template <class Type, class... Elements>
		class i<Type, list::type<Elements...>>{
		public:
			template <class...>
			using type = list::type<typename Type::template type<>, Elements...>;
		};
	public:
		template <class Type, class List>
		using type = i<Type, List>;
	};
	template <class Type, class List>
	using cons_t = cons::type<Type, List>;
}
