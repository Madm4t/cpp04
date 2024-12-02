#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria("ice") {
	(void)other;
}

Ice& Ice::operator=(const Ice& other) {
	(void)other;
	return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}