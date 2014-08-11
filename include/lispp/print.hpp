#pragma once

namespace lispp{
	template <class T>
	class print{
		char : 16;
	public:
		template <class...>
		using type = T;
	};
}
