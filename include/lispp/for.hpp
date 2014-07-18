#pragma once

namespace lispp{
	template <
		class Start
		, class End
		, class Step
		, template <class Type> class Func
		, class = void
	>
	struct for_{
	};
	template <
		template <class Type> class Func
		, int Start
		, int End
		, int Step
	>
	struct for_<
		int_<Start>
		, int_<End>
		, int_<Step>
		, Func
		, typename std::enable_if<
			(Step > 0 && Start < End)
			|| (Step < 0 && Start > End)>::type
	>{
		using type = cons_t<
			typename Func<int_<Start>>::type
			, typename for_<int_<Start + Step>
				, int_<End>
				, int_<Step>
				, Func
			>::type
		>;
	};
	template <
		template <class Type> class Func
		, int Start
		, int End
		, int Step
	>
	struct for_<
		int_<Start>
		, int_<End>
		, int_<Step>
		, Func
		, typename std::enable_if<
			(Step > 0 && Start >= End)
			|| (Step < 0 && Start <= End)
		>::type
	>{
		using type = list<>;
	};

	template <
		class Start
		, class End
		, class Step
		, template <class Type> class Func
	>
	using for_t = typename for_<Start, End, Step, Func>::type;
}
