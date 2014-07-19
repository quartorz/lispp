#pragma once

#include <ostream>

namespace lispp{
	template <class... Args>
	struct list{
		using type = list<Args...>;
		void print(std::ostream &os) const;
	};
	template <>
	struct list<>{
		using type = list<>;
		void print(std::ostream &os) const
		{
		}
	};

	using nil = list<>;


 	template <class>
	struct null{
		static constexpr bool value = false;
		using type = nil;
	};
	template <>
	struct null<nil>{
		static constexpr bool value = true;
		using type = t;
	};

	template <class...>
	struct cons{
	};
	template <class T, class... Args>
	struct cons<T, list<Args...>>{
		using type = list<T, Args...>;
	};

	template <class... Args>
	using cons_t = typename cons<Args...>::type;

	template <class>
	struct car{
	};
	template <class Head, class... Rest>
	struct car<list<Head, Rest...>>{
		using type = Head;
	};

	template <class T>
	using car_t = typename car<T>::type;

	template <class>
	struct cdr{
	};
	template <class Head, class... Rest>
	struct cdr<list<Head, Rest...>>{
		using type = list<Rest...>;
	};

	template <class T>
	using cdr_t = typename cdr<T>::type;


	template <class... Args>
	inline void list<Args...>::print(std::ostream &os) const
	{
		os << car_t<type>();
		cdr_t<type>().print(os);
	}

	std::ostream &operator<<(std::ostream &os, const list<> &)
	{
		os << "()";
		return os;
	}

	template <class... Args>
	inline std::ostream &operator<<(std::ostream &os, const list<Args...> &l)
	{
		os << "( ";
		l.print(os);
		os << ") ";
		return os;
	}
}
