#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongUnknown") {
	std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
	std::cout << "WrongAnimal parameterized constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal copy constructed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "WrongAnimal assigned." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal noise." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}