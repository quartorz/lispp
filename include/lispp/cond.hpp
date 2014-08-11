#pragma once

#include "base_types.hpp"
#include "basic.hpp"

namespace lispp{
	class cond{
		template <bool, class...>
		class ii;
		template <class First, class... Rest>
		class ii<true, First, Rest...>{
		public:
			template <class...>
			using type = typename car::type<cdr::type<typename First::template type<>>>::template type<>;
		};
		template <class First, class Second, class... Rest>
		class ii<false, First, Second, Rest...> : public ii<!null::type<car::type<typename Second::template type<>>>::value, Second, Rest...>{
		};
		template <class First, class... Rest>
		class i : public ii<!null::type<car::type<typename First::template type<>>>::value, First, Rest...>{
		};
	public:
		template <class... Args>
		using type = i<Args...>;
	};
	template <class... Args>
	using cond_t = cond::type<Args...>;
}
