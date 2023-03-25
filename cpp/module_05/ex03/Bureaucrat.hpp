/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:49:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 11:51:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat & operator=(const Bureaucrat &rhs);

		std::string getName() const;
		int getGrade() const;

		void promote();
		void demote();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif