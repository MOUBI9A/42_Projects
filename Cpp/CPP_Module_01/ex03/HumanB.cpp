/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:06 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:07 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"

HumanB::HumanB(std::string name)
{
	HumanB::setName(name);
	HumanB::setHP(100);
	this->weapon = NULL;
	std::cout << "\033[38;5;244myour weapon is your hands {damage: 1}\033[0m" << std::endl;
}
void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << "\033[38;5;244m" << name << " attacks with their hands {damage: 1}\033[0m" << std::endl;
	else
		std::cout << "\033[38;5;244m" << name << " Attacks with their " << weapon->getType() << "{damage: " << weapon->getDamage() << "}\033[0m" << std::endl;
}
void HumanB::attack(HumanA& target)
{
	if (weapon == NULL)
		std::cout << "\033[38;5;244m" << name << " attacks " << target.getName() << " with their hands {damage: 1}\033[0m" << std::endl;
	else
		std::cout << "\033[38;5;244m" << name << " attacks " << target.getName() << " with their " << weapon->getType() << "{damage: " << weapon->getDamage() << "}\033[0m" << std::endl;
	if (weapon == NULL)
		target.setHP(target.getHP() - 1);
	else
		target.setHP(target.getHP() - weapon->getDamage());
}

int HumanB::getdamage()
{
	return (weapon->getDamage());
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	std::cout << "\033[38;5;244myour weapon is a " << weapon.getType() << " {damage: " << weapon.getDamage() << "}\033[0m" << std::endl;
}
int HumanB::getHP()
{
	return (HP);
}
void HumanB::setHP(int value)
{
	HP = value;
}
std::string HumanB::getName()
{
	return (name);
}
void HumanB::setName(std::string value)
{
	name = value;
}
int HumanB::checkHP()
{
	if (HP <= 0)
		return (0);
	else
		return (1);
}