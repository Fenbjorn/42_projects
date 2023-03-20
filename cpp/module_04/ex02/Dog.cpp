/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 16:23:05 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//=============================================================================

Dog::Dog() : AAnimal()
{
	std::cout << "A good doggo come !" << std::endl;
	this->_type = "Dog";
	try
	{
		this->_brain = new Brain();
	}
	catch(const std::bad_alloc& e)
	{
		std::cout << "Allocation failed" << std::endl;
	}
}

Dog::Dog(Dog const &copy) : AAnimal(copy)
{
	std::cout << "You pay 30.000€ to clone the doggo." << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "You can't play anymore. Good bye little boy (the dog) !" << std::endl;
	delete this->_brain;
}

//=============================================================================

Dog	& Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return *this;
}

//=============================================================================

void	Dog::makeSound() const
{
	std::cout << this->_type << ": Bark bark !" << std::endl;
}

std::string	Dog::getType() const
{
	return this->_type;
}

//=============================================================================