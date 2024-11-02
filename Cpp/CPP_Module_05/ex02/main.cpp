/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 12:06:22 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{

	Bureaucrat bureaucrat("John", 5);
	std::cout << bureaucrat << std::endl;


	ShrubberyCreationForm shrubberyForm("Target1");
	std::cout << shrubberyForm << std::endl;
	bureaucrat.signForm(shrubberyForm);
	bureaucrat.executeForm(shrubberyForm);

	PresidentialPardonForm presidentialForm("Target2");
	std::cout << presidentialForm << std::endl;
	bureaucrat.signForm(presidentialForm);
	bureaucrat.executeForm(presidentialForm);

	RobotomyRequestForm robotomyForm("Target3");
	std::cout << robotomyForm << std::endl;
	bureaucrat.signForm(robotomyForm);
	bureaucrat.executeForm(robotomyForm);

	return 0;
}