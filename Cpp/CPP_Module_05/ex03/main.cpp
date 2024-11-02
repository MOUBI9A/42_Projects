/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 13:39:18 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include "Intern.hpp"

// int main(void)
// {
// 	Intern intern;

// 	// Test with existing form
// 	AForm* form1 = intern.makeForm("robotomy request", "Bender");
// 	if (form1) {
		
// 		Bureaucrat bureaucrat("Hermes Conrad", 1);
// 		form1->beSigned(bureaucrat);
// 		form1->execute(bureaucrat);
// 		// delete form1;
// 	}
// 	AForm* form2 = intern.makeForm("form", "Target");
// 	while(1);
// 	if (form2) {
// 		std::cout << "Form2 created" << std::endl;
// 	}

// 	return 0;
// }

int m(void)
{
    Intern intern;

    try {
        AForm* form1 = intern.makeForm("shrubbery creation", "Bender");
        if (form1) {
            Bureaucrat bureaucrat("Hermes Conrad", 1);
			form1->beSigned(bureaucrat);
			form1->execute(bureaucrat);
		delete form1;
        }
        AForm* form2 = intern.makeForm("non-existing form", "Target");
        if (form2) {
            std::cout << "Form2 created" << std::endl;
        }
    } catch (Intern::FormNotFoundException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

int main()
{

    m();
    system("leaks Bureaucrat");
}