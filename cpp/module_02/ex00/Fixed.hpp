/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:04:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/14 08:53:06 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedNumber;
		static int const	_bits = 8;

	public:
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		
		Fixed &	operator=(Fixed const & rhs);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif