/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:43 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 16:36:44 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	//std:: << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria("cure") {
	(void)other;
	//std:: << "Cure copy constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	(void)other;
	//std:: << "Cure assignment operator called." << std::endl;
	return *this;
}

Cure::~Cure() {
	//std:: << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const {
	//std:: << "Cure cloning cure Material." << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}