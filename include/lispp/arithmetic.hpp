#pragma once

#include "base_types.hpp"

namespace lispp{
	class add{
		template <class... Args>
		class i{
		public:
			static constexpr int value = 0;
			template <class...>
			using type = int_::type<0>;
		};
		template <class Head, class... Rest>
		class i<Head, Rest...>{
		public:
			static constexpr int value = Head::template type<>::value + i<Rest...>::value;
			template <class...>
			using type = int_::type<value>;
		};
	public:
		template <class... Args>
		using type = i<Args...>;
	};
	template <class... Args>
	using add_t = add::type<Args...>;

	class sub{
		template <class... Args>
		class i{
		public:
			static constexpr int value = 0;
			template <class...>
			using type = int_::type<0>;
		};
		template <class Head, class... Rest>
		class i<Head, Rest...>{
		public:
			static constexpr int value = Head::template type<>::value - add::type<Rest...>::value;
			template <class...>
			using type = int_::type<value>;
		};
	public:
		template <class... Args>
		using type = i<Args...>;
	};
	template <class... Args>
	using sub_t = sub::type<Args...>;
}
