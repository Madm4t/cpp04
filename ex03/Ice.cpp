/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:55 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 16:36:55 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	//std:: << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("ice") {
	(void)other;
	//std:: << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	(void)other;
	//std:: << "Ice copy assignment called." << std::endl;
	return *this;
}

Ice::~Ice() {
	//std:: << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const {
	//std:: << "Ice Cloning Ice materia." << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}