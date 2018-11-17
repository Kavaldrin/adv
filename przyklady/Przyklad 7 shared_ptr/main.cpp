#include <iostream>
#include <memory>


struct A{};

struct SDL_Texture { int m_value = 0; };

std::ostream& operator<<(std::ostream& o, const SDL_Texture& texture) { o << "Wypisuje A " << texture.m_value; return o; }

void destroyTexture(SDL_Texture* ptr) {

	//cos sie wykonuje, kasuje...
	std::cout << "Niszcze texture\n";
	delete ptr;
}

int main()
{
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<SDL_Texture> texture(new SDL_Texture, destroyTexture);
	std::weak_ptr<SDL_Texture> weak(texture);
	std::shared_ptr<A> aCopy = a;
	{
		std::shared_ptr<SDL_Texture> copy = weak.lock();
		std::shared_ptr<SDL_Texture> anotherCopy(weak);
		std::cout << *copy << " " << copy.use_count() << " " << weak.use_count() << std::endl;
		copy->m_value = 5;
	}
	std::cout << *texture << " " << weak.use_count() << std::endl;

	std::shared_ptr<SDL_Texture> &ref = texture;
	ref->m_value = 7;
	std::cout << *texture << " " << weak.use_count() << std::endl;
	
	ref.reset();
	//mozna tez uzyc expired()
	if (std::shared_ptr<SDL_Texture> copy = weak.lock()) {
		std::cout << *copy << std::endl;
	}
	else {
		std::cout << "Wskaznik zostal skasowany\n";
	}

	std::unique_ptr<int> unique = std::make_unique<int>(5);
	std::shared_ptr<int> shared(std::move(unique));

	if(!unique){
		std::cout << "unique zostal przeniesiony do shared\n";
	}


	return 0;
}