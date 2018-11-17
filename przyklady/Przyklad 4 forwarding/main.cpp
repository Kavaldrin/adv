#include <iostream>


struct A {
	A() { 
		std::cout << "A Konstruktor bezparametrowy\n";
		m_ptr = new int(5);
	}
	A(int val) { 
		std::cout << "A Konstruktor z parametrem\n";
		m_ptr = new int(val); 
	}
	~A() { delete m_ptr; }
	A(A&& a) {
		std::cout << "A konstuktor przenoszacy\n";
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}
	A& operator=(A&& a) {
		if (this != &a) {
			std::cout << "A przenoszenie poprzez operator przypisania\n";
			m_ptr = a.m_ptr;
			a.m_ptr = nullptr;
		}
		return *this;
	}
	A& operator=(const A& a) {
		if (this != &a) {
			std::cout << "A kopiowanie poprzez operator przypisania\n";
			m_ptr = new int(*a.m_ptr);
		}
		return *this;
	}
	A(const A& a) {
		std::cout << "A kontruktor kopiujacy\n";
		m_ptr = new int(*a.m_ptr);
	}


	void zmien(int& x) { 
		std::cout << "Zmiana ref lvalue\n";
		*m_ptr = x; 
	}
	void zmien(int&& x) {
		std::cout << "Zmiana ref rvalue\n";
		*m_ptr = x; 
	}

	int* m_ptr;
};

std::ostream& operator<<(std::ostream& o, const A& a) {
	o << *a.m_ptr << " " << a.m_ptr << std::endl;
	return o;
}

struct B {
	template <typename T1, typename T2>
	B(T1&& t1, T2&& t2) {
		a = std::forward<T1>(t1);
		a.zmien(std::forward<T2>(t2));
	}

	B() {
		std::cout << "B bez parametrow\n";
	}

	A a;
};

template <typename... Args>
B pelna_egzotyka(Args&&... args) 
{
	std::cout << "WOW!\n";
	B b(std::forward<Args>(args)...);
	return b;
}

template <typename T>
A f(T&& arg) 
{
	A a(std::forward<T>(arg));
	return a;
	//!!!! zwracanie przez wartosc jako przenoszenie! optymalizacja od C++11
}

int main()
{
	A a(5);
	std::cout << "-----------------------------\n";
	std::cout << "f(5) " << f(5) << std::endl;
	std::cout << "f(a) " << f(a) << std::endl;
	std::cout << "f(A(5)) " << f(A(5)) << std::endl;
	std::cout << "-----------------------------\n";


	int x = 10;
	std::cout << "-----------------------------\n";
	B b(a, x);
	std::cout << b.a << std::endl;
	std::cout << "-----------------------------\n";
	B ba(a, 7);
	std::cout << ba.a << std::endl;
	std::cout << "-----------------------------\n";
	B bb(A(), x);
	std::cout << bb.a << std::endl;
	std::cout << "-----------------------------\n";
	B bc(A(3), 2);
	std::cout << bc.a << std::endl;
	std::cout << "-----------------------------\n";

	B wow = pelna_egzotyka(a, 10); //uwaga trzeba zadbac w tej funkcji o dobra kolejnosc parametrow
	//musza one rowniez pasowac do konstruktora b

	a = 100;
	//gdy lvalue przekazuje to kopiowanie sie odbywa
	std::cout  << *wow.a.m_ptr << std::endl;
	std::cout << "-----------------------------\n";
	B wow2 = pelna_egzotyka();
	std::cout << "-----------------------------\n";
	//czemu na koncu A przenoszacy? poprzedni przyklad

	return 0;
}