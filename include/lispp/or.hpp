#pragma once

#include "int.hpp"

namespace lispp{
	namespace aux_{
		constexpr int or_impl(int n)
		{
			return n;
		}
		template <class... T>
		constexpr int or_impl(int n, T... m)
		{
			return n | or_impl(m...);
		}
	}

	template <class... Args>
	struct or_ : int_<aux_::or_impl(Args::type::value...)>{
	};
}
