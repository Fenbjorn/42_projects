/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:41:42 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 11:14:28 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(Dog const &copy);
		virtual ~Dog();

		Dog & operator=(Dog const & rhs);

		virtual void	makeSound() const;
		std::string	getType() const;
		Brain*	getBrain() const;
};

#endif