#include <vector>
#include <iostream>



template <typename... TArgs>
void funkcja(TArgs... a)
{
	std::cout << "Nie mam dopasowania do funkcji...\n";
}

void funkcja(int a, int b)
{
	std::cout << "Dopasowanie do funkcji, 2 parametry...\n";
}
void funkcja(int a, int b, int c)
{
	std::cout << "Dopasowanie do funkcji, 3 parametry...\n";
}

template <typename... TArgs>
void przeslij(TArgs... args)
{
	funkcja(args...);
}



struct A {
	A(int x, int y) {
		std::cout << "Stworzylem obiekt A, otrzymujac 2 parametry: " << x << " " << y << std::endl;
	}
	A(int x, int y, double z) {
		std::cout << "Stworzylem obiekt A, otrzymujac 3 parametry\n" << x << " " << y << " " << z << std::endl;
	}

};


template <typename... TArgs>
A stworzA(TArgs... args)
{
	return A(args...); //(1)
}

int main()
{
	przeslij();
	przeslij("dsadsa", 'a');
	przeslij(5, 2);
	przeslij(5., 1);
	przeslij(5, 4, 3);

	A a = stworzA(2, 3); //nastepuje rzutowanie by dopasowac do konstruktora
	A a2 = stworzA(5.3, 2);

	//blad kompilacji ze wzgledu na brak pasujacego konstruktora (1)
	//A klops = stworzA(5,2,3,2);

	return 0;
}