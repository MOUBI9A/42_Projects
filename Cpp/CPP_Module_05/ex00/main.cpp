/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:22:01 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:06:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
 
	try
	{

		Bureaucrat b;
    	Bureaucrat b1("b1", 50);
    	Bureaucrat b2("b2", 150);
		
		b2.addGrade();
        std::cout << b2 << std::endl;
        for (int i = 0; i < 200; i++)
        {
            b1.subGrade();
            std::cout << b1 << std::endl;
        }
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}