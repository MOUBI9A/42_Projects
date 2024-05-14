/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:59:26 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:15:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>



class ClapTrap
{
	private :
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
	public :
                ClapTrap();
                ClapTrap(std::string name);
                ClapTrap(std::string name, int damage);
                ClapTrap(const ClapTrap &src);
                ~ClapTrap();
                
                ClapTrap &operator=(const ClapTrap &src);
                
                void		setName(std::string value);
                std::string	getName();

                void		setHitPoints(int value);
                int			getHitPoints();
        
                void		setEnergyPoints(int value);
                int			getEnergyPoints();
        
                void		setAttackDamage(int value);
                int			getAttackDamage();

                void	attack(std::string const & target);
                void	takeDamage(unsigned int amount);
                void	beRepaired(unsigned int amount);
                
                void	attack(ClapTrap &target);


        
};

#endif