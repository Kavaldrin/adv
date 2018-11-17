#include <iostream>


void f(void(*fun)(int))
{
	std::cout << "Przeladowanie ze wskaznikiem funkcji\n";
	if(fun)fun(5);
}
void f(int val)
{
	std::cout << "Przeladowanie z wartoscia funkcji\n";
}

void g(int val)
{
	std::cout << val << std::endl;
}


int main()
{	
	f(5);
	//f(NULL);
	f(nullptr);
	f(g);


	return 0;
}
