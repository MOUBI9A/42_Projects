/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:42 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:43:22 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(){
	FragTrap fragTrap("FragTrap");
	ScavTrap scavTrap("ScavTrap");
	ClapTrap clapTrap("ClapTrap");

	std::cout << std::endl;
	fragTrap.attack("target");
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	scavTrap.attack("target");
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	std::cout << std::endl;
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
}
    