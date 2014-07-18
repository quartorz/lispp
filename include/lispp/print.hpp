#pragma once

namespace lispp{
	template <class T>
	struct print{
		using type = T;
		char : 16;
	};

	template <class T>
	using print_t = typename print<T>::type;
}
