/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:42:23 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:27:08 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    Bureaucrat b2("b2", 10);
    Form f1("f1", 5, 1);
	try
	{
        std::cout << f1 << std::endl;
        
        b2.signForm(f1);
        while(b2.getGrade() > f1.getToSign())
        {
            b2.work();
            std::cout << b2 << std::endl;
        }
        b2.signForm(f1);
        std::cout << f1 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}