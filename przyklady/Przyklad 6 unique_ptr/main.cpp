#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <chrono>


/*

	for (unsigned i = 0; i < normalPtrArr.size(); ++i) {
		delete normalPtrArr[i];
	}
*/





struct A {
	A(int val):m_value(val) {}
	int m_value;
};

std::ostream& operator<<(std::ostream& o, const A& a) {
	o << "Wypisanie obiektu klasy A: " << a.m_value << std::endl;
	return o;
}

struct SDL_Renderer{};
void destroyRenderer(SDL_Renderer* r)
{
	//usuwanie innych elementow...
	//wykonywane operacje
	std::cout << "Niszcze renderer\n";
	delete r;
}

void przetworz(std::unique_ptr<A> a, int param)
{
	//procesowanie czegos...

}

int policz()
{
	//skomplikowane operacje, moze dojsc do wyrzucenia wyjatku
	//throw std::exception("a");
	return 5;
}

int main()
{
	std::unique_ptr<A> ptr(new A(5));
	std::unique_ptr<A> byMake = std::make_unique<A>(5);
	std::unique_ptr<A> movedPtr(std::move(ptr));
	if (!ptr) {
		std::cout << "Oryginalny ptr jest juz nullptrem\n";
	}
	//std::unique_ptr<A> copy(movedPtr); nie da sie bo tylko jedna instacja na ten obiekt

	std::cout << *movedPtr << " " << movedPtr.get() << std::endl;
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer(new SDL_Renderer, destroyRenderer);

	////////////////////////////////////////
	//make_unique lepsze
	przetworz(std::unique_ptr<A>(new A(5)), policz()); //nie znamy kolejnosci
	//kolejnosc moze byc
	//new A()
	//policz()
	//wyjatek w policz()
	//tu by bylo przypisanie do wskaznika w unique_ptr, ale do tego nie dojdzie przez wyjatek
	//wyciek pamieci

	przetworz(std::make_unique<A>(5), policz());
	//tworzony obiekt w miejscu
	//albo od razu stworzony, albo po funkcji policz()
	//brak mozliwosci wycieku

	//rozmiar obiektu
	int *rawPtr;
	std::cout <<"Rozmiar surowego wskaznika " << sizeof(rawPtr) << " Rozmiar unique_ptr "<<  sizeof(ptr) << " Rozmiar unique_ptr z deleterem " << sizeof(renderer) << std::endl;

	//testowanie szybkosci
	std::array<A*, 100000> normalPtrArr;
	std::array<std::unique_ptr<A>, 100000> uniquePtrArr;


	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	for (unsigned i = 0; i < normalPtrArr.size(); ++i) {
		normalPtrArr[i] = new A(0);
		*(normalPtrArr[i]);
	}
	std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
	std::chrono::microseconds pointerTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	std::cout << "Surowy wskaznik czas w mikro sekundach: " << pointerTime.count() << std::endl;

	t1 = std::chrono::steady_clock::now();
	for (unsigned i = 0; i < uniquePtrArr.size(); ++i) {
		uniquePtrArr[i] = std::make_unique<A>(0);
		*(uniquePtrArr[i]);
	}
	t2 = std::chrono::steady_clock::now();
	pointerTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	std::cout << "Unique_ptr czas w mikro sekundach: " << pointerTime.count() << std::endl;
	
	//czegos brakuje? rekompensata


	

	return 0;
}