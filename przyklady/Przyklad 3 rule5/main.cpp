#include <iostream>

struct A {
	A(int val = 0):m_value(val){}
	A(const A& a) { m_value = a.m_value; }

	int m_value;
};

struct B {
	B() { m_ptr = new int(5); }
	~B() {} // wyciek z premedytacja

	int* m_ptr;
};


struct C {
	C() { m_ptr = new int(5); }
	~C() { delete m_ptr; }
	C(C&& c) {
		std::cout << "C przenoszenie\n";
		m_ptr = c.m_ptr;
		c.m_ptr = nullptr;
	}
	C(const C& c) {
		std::cout << "C kopiowanie\n";
		m_ptr = new int(*c.m_ptr);
	}
	int* m_ptr;
};

struct D {
	C c;
};


/*
	Przyklad pokazujacy zastosowanie domyslnych funkcji przenoszenia + dlaczego sa przydatne
*/

int main()
{
	A a(5);
	A aCopy(a);
	A aMoved(std::move(a));

	std::cout << "a: " << a.m_value << std::endl;
	std::cout << "aCopy: " << aCopy.m_value << std::endl;
	std::cout << "aMoved: " << aMoved.m_value << std::endl;
	//ale co sie dzieje w domyslnym move?, dla tego przykladu dziala jak kopiujacy
	//ale czy zawsze?

	B b;
	B bCopy(b);
	B bMoved(std::move(b));
	std::cout << "b: " << b.m_ptr << std::endl;
	std::cout << "bCopy: " << bCopy.m_ptr << std::endl;
	std::cout << "bMoved: " << bMoved.m_ptr << std::endl;
	//niefajnie
	//no to po co uzywac defaultowego move, skoro dziala jak widac, czyli nie za bardzo



	D d;
	std::cout << "D przed operacjami kopiowania i przenoszenia"<<std::endl;
	std::cout << d.c.m_ptr << std::endl;

	D dCopy(d);
	D dMoved(std::move(d));
	std::cout << "D wskaznik w C: " << d.c.m_ptr << std::endl;
	std::cout << "dCopy wskaznik w C: " << dCopy.c.m_ptr<< std::endl;
	std::cout << "dMoved wskaznik w C: " << dMoved.c.m_ptr << std::endl;
	//jak widac domyslny przenoszacy konstruktor jak i przenoszacy operator przypisania
	//zadzialania inteligetnie! 'sprobuja' przeniesc obiekty ktore zawieraja

	return 0;
}