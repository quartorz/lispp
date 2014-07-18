#pragma once

namespace lispp{
	template <int I>
	struct int_{
		static constexpr int value = I;
		using type = int_<I>;
	};

	struct t{
		using type = t;
	};
}
