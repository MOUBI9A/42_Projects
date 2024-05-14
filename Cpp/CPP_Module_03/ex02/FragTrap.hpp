/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:56:02 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 16:39:47 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(std::string name, int damage);
		FragTrap(FragTrap &obj);
		~FragTrap();
		FragTrap &operator=(FragTrap &obj);
		void highFivesGuys(void);

};
int printDetail();
#endif