/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:54 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string type;
	int damage;
public:
	Weapon();
	Weapon(std::string t_type);

	const std::string&  getType();
	void  setType(std::string value);

	int getDamage();
	void setDamage(int value);
};
#endif

