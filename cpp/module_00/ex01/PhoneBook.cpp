/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:37:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/10 14:20:48 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::menu(void) const
{
    std::cout << std::endl;
    std::cout << "PhoneBook menu" << std::endl;
    std::cout << std::endl;
    std::cout << "==== CHOOSE ONE OPTION ====" << std::endl;
    std::cout << "ADD:\t To add contact." << std::endl;
    std::cout << "SEARCH:\t To search contact." << std::endl;
    std::cout << "EXIT:\t To quit the PhoneBook." << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::addContact(void)
{
    int i = 0;
    this->_contact[i % 8].init();
    this->_contact[i % 8].setIndex(i % 8);
    i++;
}

void PhoneBook::printContact(void) const
{
    std::cout << "============= PHONEBOOK CONTACTS =============" << std::endl;
    for (int i = 0; i < 8; i++)
        this->_contact[i].view(i);
    std::cout << std::endl;
}

int PhoneBook::_readInput() const
{
    int  input = -1;
    bool valid = false;

    do
    {
        std::cout << "Enter contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8))
            valid = true;
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid index." << std::endl;
        }
    } while (!valid);
    return (input);
}

void PhoneBook::search(void) const
{
    int i = this->_readInput();
    this->_contact[i].display(i);
}