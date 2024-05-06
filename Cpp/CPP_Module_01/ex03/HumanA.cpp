/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:12 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon)
{
	this->name = name;
	this->HP = 100;
	std::cout << "\033[34m" << "your weapon is a " << weapon.getType() << " {damage: " << weapon.getDamage() << "}" << "\033[0m" << std::endl;
}

void HumanA::attack()
{	
	std::cout << "\033[34m" << name << " attacks with their " << weapon.getType() << "{damage: " << weapon.getDamage() << "}" << "\033[0m" << std::endl;
}

void HumanA::attack(HumanB& target)
{	
	std::cout << "\033[34m" << name << " attacks " << target.getName() << " with their " << weapon.getType() << " {damage: " << weapon.getDamage() << "}" << "\033[0m" << std::endl;
	target.setHP(target.getHP() - weapon.getDamage());
}

int HumanA::getdamage()
{
	return (weapon.getDamage());
}

int HumanA::getHP()
{
	return (HP);
}

void HumanA::setHP(int value)
{
	HP = value;
}

std::string HumanA::getName()
{
	return (name);
}

void HumanA::setName(std::string value)
{
	name = value;
}

int HumanA::checkHP()
{
	if (HP <= 0)
		return (0);
	else
		return (1);
}
