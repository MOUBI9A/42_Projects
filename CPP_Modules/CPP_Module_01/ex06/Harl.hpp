/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:01 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:02 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	
private :
	void DEBUG(void);
	void INFO(void);
	void WARNING(void);
	void ERROR(void);

public :
	void Complain(std::string Choice);
};

#endif