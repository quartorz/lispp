#pragma once

namespace lispp{
	template <template <class...> class Func, class... Args>
	struct funcall{
		using type = typename Func<Args...>::type;
	};

	template <template <class...> class Func, class... Args>
	using funcall_t = typename funcall<Func, Args...>::type;
}
