#include <list>
#include <iostream>

struct A {
	A(){
		std::cout << "A Konstruktor domyslny\n";
	}

	A(int val) {
		std::cout << "A konstruktor z parametrem\n";
	}
	A(const A& a) {
		std::cout << "A konstruktor kopiujacy\n";
	}
	A(A&& a) {
		std::cout << "A konstruktor przenoszacy\n";
	}
	int m_value;
};


int main()
{
	A a;
	std::list<A> vec;
	std::cout << "---------------\n";
	vec.push_back(a);
	std::cout << "---------------\n";
	vec.push_back(A());

	std::cout << "---------------\n";
	vec.emplace_back(A()); //tutaj zadziala jak push_back, zle uzycie
	std::cout << "---------------\n";
	vec.emplace_back(); //lepsze uzycie, zrobi to samo, wydajniej!!
	std::cout << "---------------\n";
	vec.emplace_back(5);
	std::cout << "---------------\n";
	int x = 5;
	vec.emplace_back(x);
	std::cout << "---------------\n";

	std::cout << "Emplace_back vs push_back\n\n";
	//Znaczna roznica
	std::cout << "------emplace_back---------\n";
	vec.emplace_back(5); //konstrukcja w miejscu, bez przenoszenia
	std::cout << "------push_back------------\n";
	vec.push_back(A(5)); //konstrukcja tymczasowego obiektu, nastepnie przeniesienie go
	
	return 0;
}