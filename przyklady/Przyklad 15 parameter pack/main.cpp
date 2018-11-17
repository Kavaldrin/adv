#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <typeinfo>


template <typename T>
struct A {
	A(T x, T y) {
		std::cout << x << " " << y << " typ: " << typeid(T).name() << std::endl;
	}
	A(T x, T y, T z) {
		std::cout << x << " " << y << " " << z << " typ: " << typeid(T).name() << std::endl;
	}
};

/////////////////////////
template <typename... T>
void basic(T... t)
{
	std::cout << "Liczba dostarczonych parametrow: " << sizeof...(T) << std::endl;
}
//////////////////////////

////////////////////////
template <typename T, typename... U>
void advance(T type, U... args) //parameter pack musi byc jako ostatni argument funkcji
{
	std::cout << "Liczba dostarczonych parametrow: " << sizeof...(U) << std::endl;
	A<T>(args...);
}

/////////////////////////
template <typename T,typename... Args>
void wypiszPierwszy(T pierwszy, Args... args)
{
	std::cout << pierwszy << std::endl; //dostarczony typ T musi dac sie wypisac... 
}


///////////////////////////

template <typename... Args>
void expert_1(Args... args)
{
	wypiszPierwszy(args...);
}

template <typename... Args>
void expert_2(Args... args)
{
	wypiszPierwszy(args...);
	expert_1(++args...); //dostarczone typy musza obslugiwac operator++
	wypiszPierwszy(args...);
}

template <typename... Args>
void expert_3(Args... args)
{
	wypiszPierwszy(args...);
	expert_2(*args...);
}

template <typename... Args>
void expert_4(Args... args)
{
	wypiszPierwszy(args...);
	expert_3(&args...);
}

///////////////////////////

int main()
{
	basic(1, 2, 3, 4, 5, 6, 7);

	auto type = 2.;
	auto type2 = 3u;
	advance(type, 1.5, 2u, 3.f);
	advance(type2, 1.5, 2u);
	
	expert_4(2, 3, 4);
	//expert_4(A<int>(5, 3, 2));

	return 0;
}