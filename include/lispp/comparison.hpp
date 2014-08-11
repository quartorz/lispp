#pragma once

#include <type_traits>

#include "base_types.hpp"

namespace lispp{
	class lt{
		template <class Arg1, class Arg2>
		class i{
		public:
			static constexpr bool value = Arg1::template type<>::value < Arg2::template type<>::value;
			template <class...>
			using type = typename std::conditional<value, t, nil>::type;
		};
	public:
		template <class Arg1, class Arg2>
		using type = i<Arg1, Arg2>;
	};
	template <class Arg1, class Arg2>
	using lt_t = lt::type<Arg1, Arg2>;

	class equal{
		template <class Type1, class Type2>
		class i{
		public:
			static constexpr bool value = std::is_same<Type1, Type2>::value;
			template <class...>
			using type = typename std::conditional<value, t, nil>::type;
		};
	public:
		template <class Type1, class Type2>
		using type = i<Type1, Type2>;
	};
	template <class Type1, class Type2>
	using equal_t = equal::type<Type1, Type2>;
}
