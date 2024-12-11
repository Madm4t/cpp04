/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:21 by mgering           #+#    #+#             */
/*   Updated: 2024/12/11 17:08:34 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _templates[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource &operator=(const MateriaSource &other); 
	virtual ~MateriaSource();

	void learnMateria(AMateria* m) override;
	AMateria* createMateria(std::string const& type) override;
};

#endif