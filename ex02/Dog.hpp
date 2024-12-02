#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* _brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	void makeSound() const override;
	Brain* getBrain() const;
};

#endif