#include <iostream>


template <typename T>
class PodKlasa
{
public:
	PodKlasa(T value) :m_value(value) {}


private:
	T m_value;
};


template <typename... KlasyPodstawowe>
class Klasunia : public KlasyPodstawowe...
{
public:
	Klasunia(const KlasyPodstawowe&... podKlasunie) : KlasyPodstawowe(podKlasunie)...
	{}


};


struct A {
	A(int val):m_val(val) {}
	int m_val;

};



int main()
{

	PodKlasa<int> trzymamInta(5);
	PodKlasa<double> trzymamDouble(5.2);
	PodKlasa<A> trzymamA(A(1));

	Klasunia<PodKlasa<int>, PodKlasa<double>, PodKlasa<A>> klasunia(trzymamInta, trzymamDouble,trzymamA);
	//cos przypomina ta skladnia?

	return 0;

}