/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:03 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 16:34:41 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unknown") {
	//std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string const& name) : _name(name) {
	//std::cout "Character parameterized constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name) {
	//std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character &Character::operator=(const Character &other) {
	//std::cout << " Character copy assignment operator called." << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character() {
	//std::cout "Character destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const& Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " in slot[" << i << "]" << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full. Cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >=4) {
		std::cout << " Invalid index: " << idx << std::endl;
		return;
	}
	if (_inventory[idx]) {
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << " slot [" << idx << "]" << std::endl;
		_inventory[idx] = nullptr;
	} else {
		std::cout << "No Materia to unequip at slot [" << idx << "]" << std::endl; 
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !_inventory[idx]) {
		std::cout << "Cannot use Materia at slot [" << idx << "]" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}