#include <iostream>

#include "lispp.hpp"

int main()
{
	using namespace lispp;

	using l = list<int_<1>, int_<2>, int_<5>>;

	std::cout << apply_t<add, l>() << std::endl;
	// (apply '+ '(1 2 5))

	std::cout << apply_t<mul, l>() << std::endl;
	// (apply '* '(1 2 5))

	std::cout << length_t<l>() << std::endl;
	// (length '(1 2 5))

	std::cout
		<< cond_t<
			list<
				lt_t<int_<60>, int_<10>>,
				add_t<int_<100>, int_<200>>>,
			list<
				lt_t<int_<30>, int_<20>>,
				add_t<int_<1>, int_<2>>>,
			list<
				t,
				int_<5>>>()
		<< std::endl;
	// (cond
	//     ((< 60 10) (+ 100 200))
	//     ((< 30 20) (+ 1 2))
	//     (t '5))
	//
	//   => 5

	std::cout
		<< print_t<mapcar_t<
			add
			, list<int_<1>, int_<2>, int_<3>, int_<5>>
			, list<int_<5>, int_<7>, int_<10>>>>()
		<< std::endl;
	// (mapcar #'+
	//     '(1 2 3 5)
	//     '(5 7 10))
	//
	//   => (6 9 13)

	std::cout
		<< print_t<mapcar_t<
			car
			, list<
				list<int_<1>, int_<10>>
				, list<int_<2>, int_<20>>
				, list<int_<3>, int_<30>>>>>()
		<< std::endl;;
	// (mapcar
	//     #'car
	//     '((1 10)
	//       (2 20)
	//       (3 30)))
	//
	//   => (1 2 3)

	std::cout
		<< print_t<maplist_t
			< cons
			, list<int_<1>, int_<10>>
			, list<int_<2>, int_<20>>>>()
		<< std::endl;;
	// (maplist
	//     #'cons
	//     '(1 10)
	//     '(2 20))
	//
	//   => (((1 10) 2 20)((10) 20))

	std::cout
		<< print_t<apply_t<
			c_or,
			print_t<for_t<
				int_<1>
				, int_<11>
				, int_<1>
				, identity>>>>()
		<< std::endl;
	// (apply #'or '(1 2 3 4 5 6 7 8 9 10))
	//
	//   => t

	std::cout
		<< print_t<apply_t<
			or_
			, for_t<
				int_<1>
				, int_<11>
				, int_<1>
				, identity>>>()
		<< std::endl;
	// (apply #'logior '(1 2 3 4 5 6 7 8 9 10))
	//
	//   => 15
}
