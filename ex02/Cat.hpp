#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* _brain;

public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	void makeSound() const override;
	Brain* getBrain() const;
};

#endif