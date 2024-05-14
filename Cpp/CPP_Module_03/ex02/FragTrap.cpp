/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:55:48 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:44:17 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap", 30)
{
    // setAttackDamage(30);
    setHitPoints(100);
    setEnergyPoints(100);
    std::cout << "FragTrap Default constructor called with default name FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 30)
{
    // setAttackDamage(30);
    setHitPoints(100);
    setEnergyPoints(100);
    std::cout << "FragTrap Default constructor called with name " << name << std::endl;
}

FragTrap::FragTrap(std::string name, int damage) : ClapTrap(name, damage)
{
    // setAttackDamage(damage);
    setHitPoints(100);
    setEnergyPoints(100);
    std::cout << "FragTrap Default constructor called with name " << name << std::endl;
}

FragTrap::FragTrap(FragTrap &obj)
{
    *this = obj;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &obj)
{
    if (this == &obj)
        return *this;
    std::cout << "FragTrap Assignation operator called" << std::endl;
    setName(obj.getName());
    setHitPoints(obj.getHitPoints());
    setEnergyPoints(obj.getEnergyPoints());
    setAttackDamage(obj.getAttackDamage());
    return *this;
}


int printDetail(void)
{                  
    std::cout << "\033[1;31m H     H  I  GGGG  H     H      FFFFFFF IIIIIII V         V  EEEEEEE\n";
    std::cout << " H     H  I G    G H     H      F          I     V       V   E      \n";
    std::cout << " HHHHHHH  I G      HHHHHHH      FFFFF      I      V     V    EEEEEEE\n";
    std::cout << " H     H  I G   GG H     H      F          I       V   V     E      \n";
    std::cout << " H     H  I G    G H     H      F          I        V V      E      \n";
    std::cout << " H     H  I  GGGG  H     H      F       IIIIIII      V       EEEEEEE\033[0m\n";
    return 0;
}

void    FragTrap::highFivesGuys(void)
{
    printDetail();
    std::cout << "High five guys" << std::endl;
}
