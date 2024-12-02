
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << "Dog constructor called." << std::endl; 
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructor called." << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return (_brain);
}