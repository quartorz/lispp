#include <iostream>

#include "lispp.hpp"

int main()
{
	using namespace lispp;

	using l = list<int_<1>, int_<2>, int_<5>>;

	std::cout << apply_t<add, l>::value << std::endl;
	std::cout << apply_t<mul, l>::value << std::endl;
	std::cout << length<l>::value << std::endl;

	std::cout
		<< cond_t<list<
			list<
				apply_t<lt, list<int_<60>, int_<10>>>,
				apply_t<add, cons_t<int_<100>, list<int_<100>, int_<200>>>>>,
			list<
				lt<int_<30>, int_<20>>,
				add<int_<1>, int_<2>>>,
			list<
				t,
				int_<5>>>>::value
		<< std::endl;
	// (cond
	//     ((> 60 10) (+ 100 200))
	//     ((> 30 20) (+ 1 2))
	//     (t '5))

	print_t<mapcar_t<add, list<int_<1>, int_<2>, int_<3>, int_<5>>, list<int_<5>, int_<7>, int_<10>>>>();
	print_t<mapcar_t<car, list<list<int_<1>, int_<10>>, list<int_<2>, int_<20>>, list<int_<3>, int_<30>>>>>();
	print_t<maplist_t<cons, list<int_<1>, int_<10>>, list<int_<2>, int_<20>>>>();

	print_t<c_or<print_t<for_t<int_<1>, int_<11>, int_<1>, identity>>>::type>();
	print_t<apply_t<or_, for_t<int_<1>, int_<11>, int_<1>, identity>>>();
}
