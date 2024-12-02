#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	//const AAnimal* meta = new AAnimal(); // This will cause a compilation error now
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();	

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;	

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	//meta->makeSound();	

	//delete meta;
	delete j;
	delete i;	

	return (0);
}