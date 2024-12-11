/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:04:11 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 17:04:25 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "---- Materia Source and Character Tests ----" << std::endl;

    // Create MateriaSource and learn Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create a Character named "me"
    ICharacter* me = new Character("me");

    // Create Materias from the MateriaSource
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Create another Character named "bob"
    ICharacter* bob = new Character("bob");

    // Use Materias on bob
    me->use(0, *bob); // Should output: * shoots an ice bolt at bob *
    me->use(1, *bob); // Should output: * heals bob's wounds *

    // Additional Tests
    std::cout << "\n---- Additional Tests ----" << std::endl;

    // Equip more Materias
    AMateria* anotherIce = src->createMateria("ice");
    me->equip(anotherIce);
    AMateria* anotherCure = src->createMateria("cure");
    me->equip(anotherCure);

    // Attempt to equip beyond inventory capacity
    AMateria* extraMateria = src->createMateria("ice");
    me->equip(extraMateria); // Should notify that inventory is full

    // Use all Materias
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob); // Invalid index

    // Unequip a Materia and use it
    me->unequip(1);
    me->use(1, *bob); // Should do nothing as it's unequipped

    // Clean up
    delete bob;
    delete me;
    delete src;

    // Verify no memory leaks using Valgrind or similar tools

    return 0;
}
