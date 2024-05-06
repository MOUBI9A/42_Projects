/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:05:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/25 21:05:47 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies;
	zombies = zombieHorde(6, "Zombie");
	int i = -1;
	std::cout << "\033[1;31mStart create & announce\033[0m" << std::endl;
	while(++i < 6)
	{
		std::cout << (i+1) << " -> ";
		zombies[i].announce();
	}
	std::cout << "\033[1;31mStart Destroyed\033[0m" << std::endl;
	delete[] zombies;
}