/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:43:04 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 17:02:30 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor." << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if(other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _templates[i];
			_templates[i] = nullptr;
		}
	}
	for (int i = 4; i < 4; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "Chose Materia ice or cure." << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!_templates[i]) {
			_templates[i] = m->clone();
			std::cout << " Learned Materia [" << _templates[i] << "]" << std::endl;
			delete m;
			return;
		}
	}
	std::cout << "Cannot learn more Materials. Slots are full." << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type) {
			std::cout << "Creating Materia of type: " << type << std::endl;
			return (_templates[i]->clone());
		}
	}
	std::cout << "Materia type not found." << std::endl;
	return nullptr;
}