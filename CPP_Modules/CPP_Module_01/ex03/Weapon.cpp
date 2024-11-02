/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:57 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:58 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t_type)
{
	Weapon::setType(t_type);
	Weapon::setDamage(3);
}
Weapon::Weapon()
{
	setType("Your Hands");
	setDamage(1);
}
const std::string&  Weapon::getType()
{
	return (type);
}
void  Weapon::setType(std::string value)
{
	type = value;
}
int Weapon::getDamage()
{
	return (damage);
}
void Weapon::setDamage(int value)
{
	damage = value;
}