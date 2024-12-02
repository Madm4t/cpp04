#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	//Base implementation does nothing
}

AMateria::AMateria() : type("undefined") {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	//Copying the type doesn't make sense
	(void)other;
	return (*this);
}