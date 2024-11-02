/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:25 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:26 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie* zombies = new Zombie[N];

	i = 0;
	while(i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}