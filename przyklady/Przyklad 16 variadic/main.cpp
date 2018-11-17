#include <iostream>
#include <vector>
#include <set>
#include <list>


void myPrint() {
	std::cout << "Wywolanie myPrint bez parametrow\n";
}

template <typename T>
void myPrint(T param)
{
	std::cout << "Wywolanie myPrint z jednym parametrem: ";
	std::cout << param << std::endl;
}

template <typename TFirst, typename... TArgs>
void myPrint(TFirst arg, TArgs... args)
{
	std::cout << "Wywolanie variadic templates: ";
	std::cout << arg << std::endl;
	std::cout << "Pozostala liczba argumentow: " << sizeof...(args) << std::endl;
	myPrint(args...);
}


int main()
{


	myPrint();
	myPrint("dsadas", 5, 'a', 999.51);

	return 0;

}