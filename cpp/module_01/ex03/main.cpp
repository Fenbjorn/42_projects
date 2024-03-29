/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/13 09:14:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
	
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("iron club");
	bob.attack();

	/*
	Weapon dagger = Weapon("iron cursed dagger");
	
	HumanB jim("Jim", dagger);
	jim.attack();
	dagger.setType("mythril dagger");
	jim.attack();
	*/
}