/*
Prosze napisac sprytny wskaznik, ktory bedzie podobny do unique_ptr
uproszczony unique_ptr
nie mozna korzystac z std::unique_ptr,std::shared_ptr
prosze zadbac o semantyke przenoszenia

odkomentowanie linijki 17 MUSI powodowac blad kompilacji


prosze skopiowac MyObject z poprzedniego zadania

prosze nie zmieniac pliku main.cpp
*/

#include "zad3.h"

//#define ERROR

int main()
{

	MyPointer<int> ptr(new int(5));
	MyPointer<int> ptr_make = MyPointer<int>::make_unique(8);
	MyPointer<int> ptr_empty;

	int x = 5;

	std::cout << " ----------TEST ---------\n";
	MyPointer<MyObject> ptrObj(new MyObject(2, 10));
	MyPointer<MyObject> ptrObj_make = MyPointer<MyObject>::make_unique(2,x);

	std::cout << *ptrObj;
	std::cout << *ptrObj_make;

	std::cout << " ----------TEST OK ---------\n";


	const MyPointer<int> police(new int(997));
	MyPointer<int> changable(new int(10));
	*changable = 1337;

	std::cout << " PRZED SWAPEM\n";
	std::cout << "ptr: " << *ptr << " ptr_make: " << *ptr_make << std::endl;
	ptr.swap(ptr_make);
	std::cout << " PO SWAPIE\n";
	std::cout << "ptr: " << *ptr << " ptr_make: " << *ptr_make << std::endl;

	ptr = std::move(changable);
	std::cout << *ptr << std::endl;
	if(!changable){
		std::cout << "changable wygasl\n";
	}


#ifdef ERROR
	*police = 999;

	MyPointer<int> copyPtr(ptr);
	ptr_empty = ptr;
#endif

	return 0;
}

/*
 ----------TEST ---------
Wywolanie z dwoma parametrami
Wywolanie z dwoma parametrami
x: 2 y: 10 z: 0
x: 2 y: 5 z: 0
 ----------TEST OK ---------
 PRZED SWAPEM
ptr: 5 ptr_make: 8
 PO SWAPIE
ptr: 8 ptr_make: 5
1337
changable wygasl
*/