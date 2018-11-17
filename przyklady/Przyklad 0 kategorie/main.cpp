#include <iostream>

struct A {
	int m_value = 0;
};
int f(){return 5;}
int global = 1;
int& g(){return global;}


//#define ERROR

int main()
{
	int x;
	A a;
	//Mozna pobrac wartosci, sa lvalue
	std::cout << &x << " " << &a << std::endl;
	//Mozna cos do nich przypisac, sa lvalue
	x = 5; a = A();
	//Zwrocona referencja przez funkcje jest lvalue, mozemy pobrac jej adres
	std::cout << &global << " " <<  &g() << std::endl;

	
	//Proba pobrania adresu z obiektu tymczasowego
#ifdef ERROR
	std::cout << &A() << std::endl;
#endif


	//Proba pobrania adresu literalu, ktory jest rvalue
#ifdef ERROR
	std::cout << &7 << std::endl;
#endif

	return 0;
}