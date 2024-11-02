/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:05:15 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/25 21:05:16 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string zmbname;
	public :
		Zombie( std::string name );
		~Zombie();
		void announce (void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif