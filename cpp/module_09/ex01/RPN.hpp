/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:16:44 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/26 17:32:13 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;

		RPN(const RPN &copy);
		RPN operator=(const RPN & rhs);

		void push(int nb);
		int pop();
		bool empty();

	public:
		RPN();
		~RPN();
		void execute(std::string str);

		class ErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
