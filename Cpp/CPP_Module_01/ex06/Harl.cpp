/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:05 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:06 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::DEBUG( void )
{
	std::cout << "\033[34mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\033[0m" << std::endl;
}

void Harl::INFO( void )
{
	std::cout << "\033[34mI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\033[0m" << std::endl;
}

void Harl::WARNING( void )
{
	std::cout << "\033[34mI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}
void Harl::ERROR( void )
{
	std::cout << "\033[34mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void Harl::Complain( std::string Choice )
{
	std::string Choices[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// void (Harl::*harlPtr2)(void);
	// harlPtr2 = &Harl::DEBUG;
	void (Harl::*harlPtr[4])(void);
	harlPtr[0] = &Harl::DEBUG;
	harlPtr[1] = &Harl::INFO;
	harlPtr[2] = &Harl::WARNING;
	harlPtr[3] = &Harl::ERROR;
	int i = -1;
	while (++i < 4)
	{
		if (Choice == Choices[i])
		{
			(this->*harlPtr[i])();
			break;
		}
	}
}
