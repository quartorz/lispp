#pragma once

namespace lispp{
	template <class Func, class... Args>
	class curry{
		template <class, int, class... Arg>
		class i;
		template <class Dummy, class T>
		class i<Dummy, 1,  T>{
		public:
			using type = curry<Func, Args..., T>;
		};
		template <class Dummy>
		class i<Dummy, 0>{
		public:
			using type = typename Func::template type<Args...>;
		};
	public:
		template <class... Arg>
		using type = typename i<void, sizeof...(Arg), Arg...>::type;
	};
}
