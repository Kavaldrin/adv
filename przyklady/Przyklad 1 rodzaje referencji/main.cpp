#include <iostream>
#include <string>


struct A {
	std::string m_napis = "Oryginal";
	A() { std::cout<<"Tworze A\n"; }
	~A() { std::cout<<"Kasuje A\n"; }
};

//ulatwienie notacji, moze przyjac i lvalue i rvalue i je wypisac!
std::ostream& operator<<(std::ostream& o,const A& a) {
	o << a.m_napis << std::endl;
	return o;
}

void f(const int& value) {
	std::cout << "Wypisuje liczbe " << value << std::endl;
}

template <typename T>
class TypHelper;



int main()
{

	A(); //obiekt tymczasowy, zostaje skasowany po tej linijce

	//Mozliwosc modyfikacji obiektow (juz nie tymczasowych)
	A&& a = A(); //przypisanie obiektu tymczasowego do r-wartosciowej referencji

	std::cout << &a << std::endl;
	std::cout << a;
	a.m_napis = "Zmiana";
	std::cout << a;

	//TypHelper<decltype(a)> testa;

	//Brak mozliwosci modyfikacji obiektow tymczasowych, tylko przedluzeniem im zywotnosci
	//uzywajac tej notacji
	const A& aa = A(); 
	std::cout << aa;
	//aa.m_napis = "Zmiana"; //no nie mozna bo jest const

	int value = 5;
	//wygoda uzytkownika, brak potrzeby pisania osobnych funkcji czy uzywania templatow
	f(7); //przekazywany obiekt tymczasowy, zostaje przedluzona zywotnosc w funkcji
	f(value); //przekazuje obiekt przez stala referencje, gwarancja braku modyfikacji obiektu

	return 0;
}