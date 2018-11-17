#include <iostream>


template <typename T>
void przypadek1a(T& param) {}
template <typename T>
void przypadek1b(const T& param) {}
template <typename T>
void przypadek1c(T* param) {}

template <typename T>
void przypadek2(T&& param){}

template <typename T>
void przypadek3(T param){}

/*
int tablica[5];
template <typename T>
void f(T& param); //-> ParametrType to int(&)[5]
template <typename T>
void f(T* param); //-> ParametrType to int*
*/


template <typename T>
class TypeHelper;

int main()
{

	int x = 5;
	const int constx = x;
	const int& rconstx = x;
	const int *ptr = &x;

	przypadek1a(x); // wydedukowany typ T -> int, ParametrType -> int&
	przypadek1a(constx); // wydedukowany typ T -> const int, ParametrType -> const int&
	przypadek1a(rconstx); // wydedukowany typ T -> const int (zignorowanie referencji), ParametrType -> const int&

	przypadek1b(x); // wydedukowany typ T -> int, ParametrType -> const int&
	przypadek1b(constx); // wydedukowany typ T -> int, ParametrType -> const int&
	przypadek1b(rconstx); // wydedukowany typ T ->  int (zignorowanie referencji), ParametrType -> const int&

	przypadek1c(&x); // wydedukowany typ T -> int, ParametrType -> int*
	przypadek1c(ptr); // wydedukowany typ T -> const int, ParametrType -> const int*

	przypadek2(x); // wydedukowany typ T -> int&, czyli ParametrType -> int&
	przypadek2(rconstx); //wydedukowany typ T -> const int&, czyli ParametrType -> const int&
	przypadek2(5); //wydedukowany typ T -> int, czyli ParametrType -> int&&

	przypadek3(x); //wydedukowany typ T -> int, czyli ParametrType -> int
	przypadek3(rconstx); //wydedukowany typ T -> int, czyli ParametrType -> int


	int tablica[5];
	przypadek1a(tablica); // wydedukowany typ T -> int (&)[5]!, czyli ParametrType -> int (&)[5]
	przypadek1c(tablica); // wydedukowany typ T -> int, czyli ParametrType -> int*

	//TypeHelper<decltype(rconstx)> tablicaType;

	return 0;
}