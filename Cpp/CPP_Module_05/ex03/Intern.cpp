/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:25:12 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 13:32:53 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &ref)
{
    *this = ref;
}

Intern &Intern::operator=(const Intern &ref)
{
    if (this != &ref)
        *this = ref;
    return *this;
}

Intern::~Intern()
{}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}



AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
    AForm *(Intern::*create[3])(std::string const &target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential Pardon"};
    for(int i = 0; i < 3; i++)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*create[i])(target);
        }
    }
    throw Intern::FormNotFoundException();
    return NULL;
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
