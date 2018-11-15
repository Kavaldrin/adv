/*
Zadanie zeby przyswoic sobie skladnie z przenoszeniem

Prosze zaimplementowac klase MyObject
-glosny konstruktor kopiujacy
-glosny konstruktor przenoszacy
-glosny operator przypisania
-glosny przenoszacy operator przypisania

Adresy z mojego outputu powinny byc analogiczne...

Pliku main nie mozna edytowac.
*/



#include "zad1.h"


int main()
{
	int x = 5, y = 9;

	std::cout << "-------------- TWORZE OBIEKTY --------------\n\n";
	MyObject<decltype(x)> o(&x);
	MyObject<> oFromTemp = MyObject<>(&y);
	MyObject<decltype(y)>&& rvalRef = MyObject<decltype(y)>();
	auto movedObj = std::move(MyObject<decltype(x)>(&x));
	std::cout << "\n-------------- STWORZYLEM OBIEKTY --------------\n\n";

	std::cout << "Wypisuje obiekt bez std::move\n" << oFromTemp << std::endl;
	std::cout << "Wypisuje obiekt uzywajac std::move\n" << std::move(oFromTemp) << std::endl;

	std::cout << "----- TWORZE OBIEKTY Z UZYCIEM ISTNIEJACYCH OBIEKTOW -----\n\n";
	auto oFromCopy(o);
	auto oMoved(std::move(o));
	std::cout << "\n-------------- STWORZYLEM OBIEKTY --------------\n\n";

	std::cout << "Wypisuje o po jego przeniesieniu\n" << o << std::endl;

	std::cout << "\nDokonuje wielu przypisan\n";
	o = std::move(oFromCopy = rvalRef = movedObj);

	std::cout << "\nWypisuje o po jego przenoszeniach\n" << o << std::endl;


	return 0;
}

/*

-------------- TWORZE OBIEKTY --------------

Tworze obiekt z przechowywanym adresem: 0x7fffb4449868
Tworze obiekt z przechowywanym adresem: 0x7fffb444986c
Tworze obiekt z przechowywanym adresem: 0
Tworze obiekt z przechowywanym adresem: 0x7fffb4449868
My object -> konstruktor przenoszacy

-------------- STWORZYLEM OBIEKTY --------------

Wypisuje obiekt bez std::move
Wypisuje MyObject otrzymany jako l-wartosc: 0x7fffb444986c

Wypisuje obiekt uzywajac std::move
Wypisuje MyObject otrzymany jako r-wartosc: 0x7fffb444986c

----- TWORZE OBIEKTY Z UZYCIEM ISTNIEJACYCH OBIEKTOW -----

My object -> konstuktor kopiujacy
My object -> konstruktor przenoszacy

-------------- STWORZYLEM OBIEKTY --------------

Wypisuje o po jego przeniesieniu
Wypisuje MyObject otrzymany jako l-wartosc: 0


Dokonuje wielu przypisan
My object -> operator przypisania
My object -> operator przypisania
My object -> przenoszacy operator przypisania

Wypisuje o po jego przenoszeniach
Wypisuje MyObject otrzymany jako l-wartosc: 0x7fffb4449868

*/