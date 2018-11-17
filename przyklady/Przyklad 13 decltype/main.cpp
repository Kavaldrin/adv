#include <iostream>



class Container {
public:
	int& operator[](int index) { return m_memory[index]; }
private:
	int m_memory[5];
};



auto funkcja11(Container &c,int index) -> decltype(c[index])
{
	return c[index];
	//ok, na podstawie decltype, ktore okresla rzeczywisty typ (z & itd...)
}

auto funkcja14zle(Container &c, int index)
{
	return c[index];
	//dedukcja 3 przypadek, czyli int! bez referencji
}

decltype(auto) funkcja14ok(Container &c, int index)
{
	return c[index];
	//dzieki decltype auto dostaje caly typ, wlacznie z referencjami
}



template <typename T>
class TypeHelper;

int main()
{
	Container c;
	funkcja11(c, 2) = 5;
	std::cout << c[2] << std::endl;

	//funkcja14zle(c, 2) = 5;
	funkcja14ok(c, 2) = 7;
	std::cout << c[2] << std::endl;


	auto var = 10;
	const auto& crvar = var;

	auto copy = crvar;
	decltype(auto) ref = crvar;

	//TypeHelper<decltype(ref)> printRef;
	//TypeHelper<decltype(copy)> printCopy;

	return 0;
}