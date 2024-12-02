#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	const int ARRAY_SIZE = 4;
	Animal* animals[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (i < ARRAY_SIZE / 2) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}

	std::cout << "\nTesting makeSound():" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		animals[i]->makeSound();
	}

	std::cout << "\n\nDeleting Animals:" << std::endl;
	for (int i =0; i < ARRAY_SIZE; ++i) {
		delete animals[i];
	}

	std::cout << "\n\nTesting Deep Copy:" << std::endl;
	Dog dog1;
	dog1.makeSound();
	dog1.getBrain()->setIdea(0, "I want a bone");
	dog1.getBrain()->setIdea(1, "I want more food");
	dog1.getBrain()->setIdea(101, "this is too much");
	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "I want a ball");

	std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1's second idea: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog1's 100 idea: " << dog1.getBrain()->getIdea(100) << std::endl;
	std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2's second idea: " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Cat cat1;
	cat1.makeSound();
	cat1.getBrain()->setIdea(0, "I want to sleep");
	Cat cat2;
	cat2 = cat1;
	cat2.getBrain()->setIdea(0, "I want to eat");

	std::cout << "Cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	return (0);
}