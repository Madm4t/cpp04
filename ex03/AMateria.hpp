#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; //Forward declaration

class AMateria
{
protected:
	std::string const type;

public:
	AMateria(std::string const & type);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

private:
	AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
};

#endif