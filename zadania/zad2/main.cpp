/*
Zadanie ma na celu zrozumienie perfect forwardingu

Prosze napisac prosty kontener
Do dadawania obiektu nalezy napisac dwie metody
emplace_back, ktore bedzie tworzyc wywolywac konstruktor z przeslanymi parametrami,
obiekt bedzie tworzony w miejscu
push_back, ktore bedzie tworzyc obiekty przez kopie/przenoszenie

Nie wolno uzywac zadnych kontenerow z STL oprocz std::array
dbalosc o pamiec nie jest tu kluczowa, mozna po prostu stworzyc tablice np 10 wskaznikow na element. -> std::array<type*,10>

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

	myContainer<MyObject> container;
	std::cout << "------ UZYCIE PUSH_BACK ------\n";
	container.push_back(obj2);
	container.push_back(std::move(obj2));
	container.push_back(MyObject(5));
	std::cout << "\n------ UZYCIE EMPLACE_BACK ------\n";
	container.emplace_back(0);
	container.emplace_back(0, 1);
	container.emplace_back(0, 1, 2);
	container.emplace_back(obj3);
	container.emplace_back(std::move(obj3));

	std::cout << "\n\n ----- KLUCZOWA ROZNICA WYDAJNOSCI ---------\n";
	std::cout << "W obu przypadkach chcemy stworzyc nowy obiekt z parametrem 5\n";
	std::cout << "push_back\n";
	container.push_back(MyObject(5));
	std::cout << "\nemplace_back\n";
	container.emplace_back(5);


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
*/