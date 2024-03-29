/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:18:05 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 11:18:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	billy("Billy");
	ScavTrap	bob("Bob");
	
	billy.attack("Bob");
	bob.attack("Billy");
	billy.takeDamage(20);
	billy.beRepaired(5);
	bob.guardGate();
}