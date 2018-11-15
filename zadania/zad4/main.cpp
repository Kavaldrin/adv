/*
luzniejsze zadanie na deser
majace na celu zachecenie do korzystania z typu auto
oraz do praktycznego zastosowania modulow chrono i random
zakaz uzywania funkcji rand() oraz naglowkow <ctime> <time.h>
prosze doprowadzic do zadanego outputu

uwaga nie mozna uzywac jawnych typow, mozna uzywac tylko auto i decltype do pomocy oraz typow szablonowych 
dozwolone jawne typy - void
jawne typy sa rowniez dozwolone przy uzyciu chrono oraz random, lecz tylko w ciele funkcji

*/

#include "zad4.h"


int main()
{

	std::cout << "----------TEST----------\n";
	auto x = 10;
	auto& y = x;
	f(y) = 12;
	std::cout << x << std::endl;
	std::cout << "----------TEST----------\n";

	std::cout << "Prosze mi wygenreowac liczbe z przedzialu [0,100]" << std::endl;
	std::cout << "a nastepnie zwrocic mi ta liczbe w unique_ptr\n";
	auto dobraRobota = wygeneruj(0, 100);
	std::cout << "Ladna liczba: " << *dobraRobota << std::endl;
	
	std::cout << "Teraz prosze wygenerowac mi ta liczbe duzo razy! i zmierzyc ile to potrwa milisekund\n";
	auto duzo = 200000;
	auto superRobota = zmierzCzas(duzo,0,100, wygeneruj<decltype(duzo)>); //oj leciutka podpowiedz!
	std::cout << "Trwalo to: " << superRobota.count() << " milisekund\n";

	std::array<int, 5> arr{ 1,2,3,4,5 };
	wyswietl(arr);
	std::vector<int> vec{ 5,4,3,2,1 };
	wyswietl(vec);
	std::list<int> list{ 1,5,2,4,3 };
	wyswietl(list);


	auto&& zagadka = f(x);
	auto&& niezagadka = f(7);
	std::cout << "zagadke zmienic moge, teraz rowna sie 12\n";
	zagadka += 1000;
	std::cout << "o prosze bardzo, a teraz 1012\n";
	std::cout << "a co sie stalo z iksem? ojojoj " << x << std::endl;

	std::cout << zagadka << " "<< niezagadka << std::endl;




	return 0;
}

/*
----------TEST----------
12
----------TEST----------
Prosze mi wygenreowac liczbe z przedzialu [0,100]
a nastepnie zwrocic mi ta liczbe w unique_ptr
Ladna liczba: 79
Teraz prosze wygenerowac mi ta liczbe duzo razy! i zmierzyc ile to potrwa milisekund
Trwalo to: 110 milisekund
1 2 3 4 5 
5 4 3 2 1 
1 5 2 4 3 
zagadke zmienic moge, teraz rowna sie 12
o prosze bardzo, a teraz 1012
a co sie stalo z iksem? ojojoj 1012
1012 7
*/