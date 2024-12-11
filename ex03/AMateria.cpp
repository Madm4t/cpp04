/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:28 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 16:36:29 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("undefined") {
	//std::cout << "Default AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	//std::cout << "Parameterized AMateria constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	//std::cout << "AMateria Copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	//Copying the type doesn't make sense
	(void)other;
	return (*this);
}

AMateria::~AMateria() {
	//std::cout << "Destructor AMateria called." << std::endl;
}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	//Base implementation does nothing
}