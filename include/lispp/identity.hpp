#pragma once

namespace lispp{
	template <class T>
	struct identity{
		using type = T;
	};

	template <class T>
	using identity_t = typename identity<T>::type;
}
