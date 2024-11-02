/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:29 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:30 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{

	private:
		std::string zmbname;
	public:
		Zombie();
		~Zombie();
		void announce (void);
		void setName( std::string name );

};

Zombie* zombieHorde( int N, std::string name );
#endif