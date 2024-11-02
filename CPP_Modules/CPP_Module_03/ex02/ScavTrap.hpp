/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:59 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:15:08 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
        ScavTrap(std::string name, int damage);
		ScavTrap(ScavTrap &obj);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &obj);

		void				attack(const std::string& target);
		void				guardGate();
		
		void				attack(ClapTrap &target);
};
#endif