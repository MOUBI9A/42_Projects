/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:05:12 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/25 21:05:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	zmbname = name;
}
Zombie::~Zombie()
{
	std::cout << zmbname << " destroyed" << std::endl;
}
void Zombie::announce (void)
{
	std::cout << zmbname << ": BraiiiiiiinnnzzzZ..." << std::endl;
}