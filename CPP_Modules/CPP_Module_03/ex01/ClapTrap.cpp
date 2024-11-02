/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:03:06 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:16:00 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("DIIB"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap default constructor called with default name DIIB" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int damage) : name(name), hit_points(10), energy_points(10), attack_damage(damage) {
    std::cout << "ClapTrap constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &src) {
        this->name = src.name+" copy";
        this->hit_points = src.hit_points;
        this->energy_points = src.energy_points;
        this->attack_damage = src.attack_damage;
    }
    return *this;
}

void ClapTrap::setName(std::string value) {
    name = value;
}

std::string ClapTrap::getName() {
    return name;
}

void ClapTrap::setHitPoints(int value) {
    hit_points = value;
}

int ClapTrap::getHitPoints() {
    return hit_points;
}

void ClapTrap::setEnergyPoints(int value) {
    energy_points = value;
}

int ClapTrap::getEnergyPoints() {
    return energy_points;
}

void ClapTrap::setAttackDamage(int value) {
    attack_damage = value;
}

int ClapTrap::getAttackDamage() {
    return attack_damage;
}

void ClapTrap::attack(std::string const & target)
{
    if(energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack, energy points are empty!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " take " << amount << " points of damage!" << std::endl;
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(hit_points + amount > 10)
    {
        std::cout << "ClapTrap " << name << " can't be repaired more than 10 points!" << std::endl;
        return;
    }
    if(energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " can't be repaired, energy points are empty!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " be repaired by " << amount << " points!" << std::endl;
    hit_points += amount;
    energy_points --;
}

void ClapTrap::attack(ClapTrap &target)
{
    if(energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack, energy points are empty!" << std::endl;
        return;
    }
    if(target.getHitPoints() > 0)
    {
        energy_points--;
        std::cout << "ClapTrap " << name << " attack " << target.getName() << ", causing " << attack_damage << " points of damage!" << std::endl;
        target.takeDamage(attack_damage);
        if(target.getHitPoints() == 0)
        {
            std::cout << this->name << " killed " << target.getName() << std::endl;
            this->setEnergyPoints(10);
            std::cout << this->name << " gained full energy points!" << std::endl;
        }
    }
    else
        std::cout << "ClapTrap " << target.getName() << " is already dead!" << std::endl;
}
