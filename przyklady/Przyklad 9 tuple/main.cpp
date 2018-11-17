#include <iostream>
#include <tuple>


template <typename... T>
auto fun(T&&... args)
{
	return std::make_tuple(std::forward<T>(args)...);
}



int main()
{
	std::tuple<int, char, std::string> a(5, 'x', "adv");
	std::tuple<int, char, std::string> b = std::make_tuple(6, 'y', "adv");
	//std::tuple<int, char, std::string> c = std::make_tuple(6, "qqq", "adv");

	char ch;
	int num;
	std::tie(num, ch, std::ignore) = a;
	std::cout << num << " " << ch << std::endl;

	std::get<2>(b) = ch;
	std::cout << ch << std::endl;

	auto generatedTuple = fun(1,2,3,4,5);
	std::cout << std::get<1>(generatedTuple) << std::endl;

	return 0;
}