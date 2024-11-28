#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown") {
	std::cout << type << " (WrongAnimal) constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << type << " (WrongAnimal) copy constructed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << type << " (WrongAnimal) assigned." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << type << " (WrongAnimal) destructed." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << type << " WrongAnimal noise." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}