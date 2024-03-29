/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:44:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 17:06:04 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//==============================Constructors & Destructor======================

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

//=================================Overload operators==========================

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return *this;
}

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

//======================================Getters================================

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

//======================================Methods================================

void Bureaucrat::promote()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::demote()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		std::cout << this->_name << " execute " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " form because: " << e.what() << std::endl;
	}
	
}

//=====================================Exceptions==============================

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

//=============================================================================