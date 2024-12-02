#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown") {
	std::cout << "(Animal) constructed." << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type) {
	std::cout << "Animal parameterized constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << "(Animal) copy constructed." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "(Animal) assigned." << std::endl;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << type << " (Animal) destructed." << std::endl;
}

std::string AAnimal::getType() const {
	return (type);
}