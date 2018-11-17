#include <chrono>
#include <iostream>
#include <vector>

template <typename T, template <typename> class allocator = std::allocator>
class Container {
public:
	Container(size_t size = 10) :m_size(size){
		m_memory = m_allocator.allocate(size);
	}
	~Container() {
		m_allocator.deallocate(m_memory, m_size);
	}
	Container(const Container& c) {
		std::cout << "Konstruktor kopiujacy\n";
		m_size = c.m_size;
		m_memory = m_allocator.allocate(c.m_size);
		for (unsigned i = 0; i < m_size; ++i) {
			m_memory[i] = c.m_memory[i];
		}
	}
	Container(Container&& c) {
		std::cout << "Konstruktor przenoszacy\n";
		m_memory = c.m_memory;
		m_size = c.m_size;
		c.m_memory = nullptr;
		c.m_size = 0;
	}

	Container& operator=(const Container& c) {
		std::cout << "Operator przypisania\n";
		if (this != &c) {
			m_size = c.m_size;
			m_memory = m_allocator.allocate(c.m_size);
			for (unsigned i = 0; i < m_size; ++i) {
				m_memory[i] = c.m_memory[i];
			}
		}
	}

	Container& operator=(Container&& c) {
		std::cout << "Przenoszacy operator przypisania\n";
		if (this != &c) {
			m_memory = c.m_memory;
			m_size = c.m_size;
			c.m_memory = nullptr;
			c.m_size = 0;
		}
	}

	T& operator[](std::size_t index) {
		return m_memory[index];
	}

	std::size_t size() const{
		return m_size;
	}
	

private:
	std::size_t m_size;
	T* m_memory;
	allocator<T> m_allocator;
};

struct A {
	A() { ++counter; }
	A(const A& a) { ++counter; m_value = a.m_value;}
	A& operator=(const A& a) { ++counter; m_value = a.m_value; return *this; }
	~A() { --counter; }
	int m_value;
	static int counter;
};

int A::counter = 0;

int main()
{
	constexpr int DUZO = 10e6;
	Container<A> c(DUZO);
	for (unsigned i = 0; i < c.size(); ++i) {
		c[i] = A(); //UWAGA przenoszenie
	}

	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	Container<A> newC(c);
	std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
	std::chrono::microseconds copyTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	std::cout << "Czas dzialania konstruktora kopiujacego: " << copyTime.count() << std::endl;
	std::cout << "Ilosc obiektow A w pamieci: " << A::counter << std::endl;
	std::cout << "Ilosc elementow w c: " << c.size() << std::endl;
	std::cout << "Ilosc elementow w newC: " << newC.size() << std::endl;
	//optymalizacja pamieci i liczby operacji

	t1 = std::chrono::steady_clock::now();
	Container<A> newMovedC(std::move(c));
	t2 = std::chrono::steady_clock::now();
	copyTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	std::cout <<"Czas dzialania konstruktora przenoszacego: " << copyTime.count() << std::endl;
	std::cout << "Ilosc obiektow A w pamieci: " << A::counter << std::endl;
	std::cout << "Ilosc elementow w c: " << c.size() << std::endl;
	std::cout << "Ilosc elementow w newC: " << newC.size() << std::endl;
	std::cout << "Ilosc elementow w newMovedC: " << newMovedC.size() << std::endl;


	//a co jesli w operacji przypisania A, bylby skomplikowany algorytm ktory by sprawdzal czy skopiowac dany obiekt?
	//a w operacji konstruktora kopiujacego bylby skomplikowany algorytm ktory by sprawdzal czy obiekt moze zostac utworzony?

	return 0;
}