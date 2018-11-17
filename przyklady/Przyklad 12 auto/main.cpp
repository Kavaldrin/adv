#include <iostream>

template <typename T>
void wypisuje(T param)
{
	std::cout << "Inny typ: " << param << std::endl;
}
void wypisuje(double param)
{
	std::cout << "Wypisuje double " << param<<std::endl;
}
void wypisuje(int param)
{
	std::cout << "Wypisuje int " << param<<std::endl;
}
void wypisuje(float param)
{
	std::cout << "Wypisuje float " << param<<std::endl;
}


template <typename T>
class TypeHelper;

int main()
{
	auto x = 3;
	auto y = 3. + 2;
	auto z = 3.f;
	auto u = 4u;

	wypisuje(x); wypisuje(y); wypisuje(z); wypisuje(u);

	//przypadek 1
	auto& rx = x;
	const auto& crx = x;
	auto* ptr = &x;

	std::cout << x << " " << crx << std::endl;
	x = 6;
	std::cout << x << " " << crx << std::endl;
	//crx = 5;
	//przypadek 2
	auto&& lvaluer = x;
	auto&& rvaluer = 5;

	//przypadek 3
	auto copyx = x;

	TypeHelper<decltype(lvaluer)> checklvaluer;
	TypeHelper<decltype(rvaluer)> checkrvaluer;


	const auto cx = 12;
	auto &rcx = cx;
	//rcx = 5;
	std::cout << cx << std::endl;

	//TypeHelper<decltype(rcx)> checkrcx;

	return 0;

}