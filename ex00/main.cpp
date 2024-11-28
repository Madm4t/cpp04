#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();

	std::cout << meta2->getType() << std::endl;
	std::cout << j2->getType() << std::endl;

	j2->makeSound();
	meta2->makeSound();

	delete meta2;
	delete j2;

	return (0);
}