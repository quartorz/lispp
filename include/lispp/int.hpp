#pragma once

namespace lispp{
	template <int I>
	struct int_{
		static constexpr int value = I;
		using type = int_<I>;		
		void print(std::ostream &os)
		{
			os << I << ' ';
		}
	};

	struct t{
		using type = t;
	};


	template <int I>
	inline std::ostream &operator<<(std::ostream &os, const int_<I> &)
	{
		os << I << ' ';
		return os;
	}

	inline std::ostream &operator<<(std::ostream &os, const t &)
	{
		os << "t ";
		return os;
	}
}
