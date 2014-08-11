#include "lispp/lispp.hpp"

using namespace lispp;

template <class From, class To, class N>
using move_disk = list_t<list_t<N, From, To>>;

template <class From, class To, class Spare, class N>
class transfer : public cond_t<
	list_t<equal_t<N, int_t<1>>, move_disk<From, To, int_t<1>>>,
	list_t<t, append_t<
		transfer<From, Spare, To, typename sub_t<N, int_t<1>>::template type<>>,
		move_disk<From, To, N>,
		transfer<Spare, To, From, typename sub_t<N, int_t<1>>::template type<>>>>>{
};

template <int N>
using hanoi = transfer<char_t<'A'>, char_t<'B'>, char_t<'C'>, int_t<N>>;

int main()
{
	print<hanoi<3>::type<>>();
}
