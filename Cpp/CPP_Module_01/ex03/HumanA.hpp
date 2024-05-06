/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:09 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:10 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanB;

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
		int HP;
		public:
			HumanA(std::string name, Weapon& weapon);
			std::string getName();
			void setName(std::string value);
			
			void attack();
			void attack(HumanB& target);
			
			int getdamage();
			int getHP();
			void setHP(int value);
			int checkHP();

};

#endif