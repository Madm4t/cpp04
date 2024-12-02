
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << "Cat constructor called." << std::endl; 
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor called." << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called." << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return (_brain);
}