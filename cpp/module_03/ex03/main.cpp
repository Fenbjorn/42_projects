/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:18:05 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 14:45:52 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap	billy("Billy");
	ScavTrap	bob("Bob");
	FragTrap	richard("Richard");
	DiamondTrap	jimmy("Jimmy");

	std::cout << std::endl;

	billy.attack("Bob");
	bob.attack("Billy");
	billy.takeDamage(20);
	billy.beRepaired(50);
	bob.guardGate();
	richard.attack("Bob");
	std::cout << "Thanks to Bob's skill, the damage he takes is reduced by 5" << std::endl;
	bob.takeDamage(25);
	bob.beRepaired(5);
	richard.highFivesGuys();
	bob.attack("Richard");
	richard.takeDamage(20);
	richard.beRepaired(10);
	jimmy.attack("Richard");
	richard.takeDamage(30);
	jimmy.guardGate();
	jimmy.highFivesGuys();
	jimmy.beRepaired(5);
	jimmy.whoAmI();
	richard.attack("Jimmy");
	jimmy.takeDamage(30);

	std::cout << std::endl;
}