/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:01:12 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 16:06:19 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];

public:
	Character();
	Character(std::string const& name);
	Character(const Character& other);
	Character &operator=(const Character& other);
	virtual ~Character();

	std::string const& getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

#endif