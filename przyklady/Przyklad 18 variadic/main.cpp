#include <iostream>


template <typename T>
double sumowanie(T param)
{
	return param;
}

template <typename T,typename... TArgs>
double sumowanie(T first,TArgs... args) {
	return first + sumowanie(args...);
}


int main()
{
	std::cout << sumowanie(5, 5, 5, 5, 20, 5.f, 5.1) << std::endl;
	return 0;
}