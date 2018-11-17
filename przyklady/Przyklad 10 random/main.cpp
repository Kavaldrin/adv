#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include <algorithm>

constexpr int DUZO = 10e6;

int main()
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> distribution(0,9);

	std::array<int, 10> arr;
	for (unsigned i = 0; i < arr.size(); ++i) {
		arr[i] = 0;
	}

	for (unsigned i = 0; i < DUZO; ++i) {
		++arr[distribution(generator)];
	}

	std::cout << "Rozklad dla mt19937\n";
	for (unsigned i = 0; i < arr.size(); ++i) {
		std::cout << i << ": "<< arr[i] << std::endl;
	}
	std::cout << *std::max_element(arr.cbegin(),arr.cend()) - *std::min_element(arr.cbegin(), arr.cend()) << std::endl;
	
	


	//////////rand()
	srand(NULL);
	for (unsigned  i = 0; i < arr.size(); ++i) {
		arr[i] = 0;
	}

	for (unsigned  i = 0; i < DUZO; ++i) {
		++arr[rand() % 10];
	}

	std::cout << "Rozklad dla rand()\n";
	for (unsigned i = 0; i < arr.size(); ++i) {
		std::cout << i << ": " << arr[i] << std::endl;
	}
	std::cout << *std::max_element(arr.cbegin(), arr.cend()) - *std::min_element(arr.cbegin(), arr.cend()) << std::endl;
	std::cout << "To dlaczego? rand() takie zle \n";



	return 0;
}

