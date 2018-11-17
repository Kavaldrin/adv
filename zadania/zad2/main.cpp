/*
Zadanie ma na celu zrozumienie perfect forwardingu i zastosowanie go praktycznie

Prosze napisac prosty kontener, ktorego metody beda przypominac metody std::vector
Do dadawania obiektu nalezy napisac dwie metody
emplace_back, ktore bedzie tworzyc wywolywac konstruktor z przeslanymi parametrami,
obiekt bedzie tworzony w miejscu
push_back, ktore bedzie tworzyc obiekty przez kopie/przenoszenie

do efektywnego dzialania emplace_back prosze alokowac pamiec alokatorem, i uzywac new placement
prosze alokowac pamiec co dziesiec elementow

informacje na temat placemenet new
https://en.cppreference.com/w/cpp/language/new
https://www.geeksforgeeks.org/placement-new-operator-cpp/

Prosze rowniez napisac prosta klase reprezentujaca wspolrzedne x,y,z
z glosnymi konstruktorami
Dzialanie jak w outputcie

Nie wolno zmieniac pliku main.cpp
*/

#include "zad2.h"
#include "zad2.h" //to nie jest blad 

int main()
{
	std::cout << "-----TEST----\n";
	MyObject obj1;
	MyObject obj2(1);
	MyObject obj3(1,2);
	MyObject obj4(1,2,3);
	MyObject obj5(obj1);
	MyObject obj6(std::move(obj1));
	std::cout << "-----ENDTEST----\n\n";

	MyContainer<MyObject> container;
	std::cout << "------ UZYCIE PUSH_BACK ------\n";
	container.push_back(obj2);
	container.push_back(std::move(obj2));
	container.push_back(MyObject(5));
	std::cout << "\n------ UZYCIE EMPLACE_BACK ------\n";
	container.emplace_back(10);
	container.emplace_back(39, 1);
	container.emplace_back(111, 1, 2);
	container.emplace_back(obj3);
	container.emplace_back(std::move(obj3));

	std::cout << "\n\n ----- KLUCZOWA ROZNICA WYDAJNOSCI ---------\n";
	std::cout << "W obu przypadkach chcemy stworzyc nowy obiekt z parametrem 5\n";
	std::cout << "push_back\n";
	container.push_back(MyObject(5));
	std::cout << "\nemplace_back\n";
	container.emplace_back(5);

	std::cout << "\n\nPo dodaniu 10 elementow...\n\n";
	container.emplace_back(992, 12, 2);

	std::cout << "\nWypisuje kontener\n";
	std::cout << container << std::endl;


	return 0;

}

/*
-----TEST----
Wywolanie bez parametrow
Wywolanie z jednym parametrem
Wywolanie z dwoma parametrami
Wywolanie z trzema parametrami
Wywolanie konstruktora kopiujacego
Wywolanie konstruktora przenoszacego
-----ENDTEST----

------ UZYCIE PUSH_BACK ------
Wywolanie konstruktora kopiujacego
Wywolanie konstruktora przenoszacego
Wywolanie z jednym parametrem
Wywolanie konstruktora przenoszacego

------ UZYCIE EMPLACE_BACK ------
Wywolanie z jednym parametrem
Wywolanie z dwoma parametrami
Wywolanie z trzema parametrami
Wywolanie konstruktora kopiujacego
Wywolanie konstruktora przenoszacego


 ----- KLUCZOWA ROZNICA WYDAJNOSCI ---------
W obu przypadkach chcemy stworzyc nowy obiekt z parametrem 5
push_back
Wywolanie z jednym parametrem
Wywolanie konstruktora przenoszacego

emplace_back
Wywolanie z jednym parametrem


Po dodaniu 10 elementow...

Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie konstruktora przenoszacego
Wywolanie z trzema parametrami

Wypisuje kontener
0: x: 1 y: 0 z: 0
1: x: 1 y: 0 z: 0
2: x: 5 y: 0 z: 0
3: x: 10 y: 0 z: 0
4: x: 39 y: 1 z: 0
5: x: 111 y: 1 z: 2
6: x: 1 y: 2 z: 0
7: x: 1 y: 2 z: 0
8: x: 5 y: 0 z: 0
9: x: 5 y: 0 z: 0
10: x: 992 y: 12 z: 2

*/