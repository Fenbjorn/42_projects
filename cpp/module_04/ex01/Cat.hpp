/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:08:49 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 11:12:50 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(Cat const &copy);
		virtual ~Cat();

		Cat & operator=(Cat const & rhs);

		virtual void	makeSound() const;
		std::string	getType() const;
		Brain*	getBrain();
};

#endif