/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:57 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:16:57 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", 20)
{
    // setAttackDamage(20);
    setHitPoints(100);
    setEnergyPoints(50);
    std::cout << "ScavTrap Default constructor called with default name ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 20)
{
    // setAttackDamage(20);
    setHitPoints(100);
    setEnergyPoints(50);
    std::cout << "ScavTrap Default constructor called with name " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name, int damage) : ClapTrap(name, damage)
{
    // setAttackDamage(damage);
    setHitPoints(100);
    setEnergyPoints(50);
    std::cout << "ScavTrap Default constructor called with name " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
    *this = obj;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj)
{
    if (this == &obj)
        return *this;
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    setName(obj.getName());
    setHitPoints(obj.getHitPoints());
    setEnergyPoints(obj.getEnergyPoints());
    setAttackDamage(obj.getAttackDamage());
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " can't attack, energy points are empty!" << std::endl;
        return;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ScavTrap " << getName() << " attack " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    
}

void ScavTrap::attack(ClapTrap &target)
{
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " can't attack, energy points are empty!" << std::endl;
        return;
    }
    if (target.getHitPoints() > 0)
    {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ScavTrap " << getName() << " attack " << target.getName() << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        target.takeDamage(getAttackDamage());
        if (target.getHitPoints() == 0)
        {
            std::cout << "ScavTrap " << getName() << " killed " << target.getName() << "!" << std::endl;
            this->setEnergyPoints(this->getEnergyPoints() + 10);
            std::cout << "ScavTrap " << getName() << " energy points increased by 10!" << std::endl;
        }
    }
    else
        std::cout << "ScavTrap " << getName() << " can't attack " << target.getName() << ", target is already dead!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode!" << std::endl;
}