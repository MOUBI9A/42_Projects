/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:03 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:04 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanA;

class HumanB {

private:
	std::string name;
	int HP;
	Weapon *weapon;

public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);

	void attack();
	void attack(HumanA& target);

	std::string getName();
	void setName(std::string value);
	
	int getdamage();
	int getHP();
	void setHP(int value);
	int checkHP();
};

#endif