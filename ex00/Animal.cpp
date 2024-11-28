#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
	std::cout << "(Animal) constructed." << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Animal parameterized constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "(Animal) copy constructed." << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "(Animal) assigned." << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << type << "(Animal) destructed." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal noise." << std::endl;
}

std::string Animal::getType() const {
	return (type);
}