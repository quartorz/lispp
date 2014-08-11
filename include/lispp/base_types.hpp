#pragma once

namespace lispp{
	class int_{
		template <int I>
		class i{
		public:
			static constexpr int value = I;
			template <class...>
			using type = i<I>;
		};
	public:
		template <int I>
		using type = i<I>;
	};
	template <int I>
	using int_t = int_::type<I>;

	class char_{
		template <char C>
		class i{
		public:
			static constexpr char value = C;
			template <class...>
			using type = i<C>;
		};
	public:
		template <char C>
		using type = i<C>;
	};
	template <char C>
	using char_t = char_::type<C>;

	class string{
		template <char... Chars>
		class i{
		public:
			template <class...>
			using type = i<Chars...>;
		};
	public:
		template <char... Chars>
		using type = i<Chars...>;
	};
	template <char... Chars>
	using string_t = string::type<Chars...>;

	class list{
		template <class... Elements>
		class i{
		public:
			template <class...>
			using type = i<Elements...>;
		};
	public:
		template <class... Elements>
		using type = i<Elements...>;
	};
	template <class... Elements>
	using list_t = list::type<Elements...>;

	using nil = list::type<>;

	class t{
	public:
		static constexpr bool value = true;
		template <class...>
		using type = t;
	};
}
