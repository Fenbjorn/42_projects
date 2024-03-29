/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:20:27 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 11:14:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//=============================================================================

Cat::Cat() : AAnimal()
{
	std::cout << "A demon euh... a cat appeared" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : AAnimal(copy)
{
	std::cout << "The copy-cat is arrived." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "The little devil (the cat) walks away with contempt" << std::endl;
	delete this->_brain;
}

//=============================================================================

Cat	& Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

//=============================================================================

void	Cat::makeSound() const
{
	std::cout << this->_type << ": Nyanyajyuu nyanya do no " << std::flush;
	std::cout << "nyarabi de nyaku nyaku inyanyaku nyanyahan " << std::flush;
	std::cout << "nyanyadai nyan nyaku nyarabete nyaganyagame !" << std::endl;
}

std::string	Cat::getType() const
{
	return this->_type;
}

Brain*	Cat::getBrain()
{
	return this->_brain;
}

//=============================================================================