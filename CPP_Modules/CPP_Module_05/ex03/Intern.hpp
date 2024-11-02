
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{

    public:
        Intern();
        Intern(Intern const &src);
        Intern &operator=(Intern const &src);
        ~Intern();

        AForm *makeForm(std::string const &name, std::string const &target);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class InvalidFormNameException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        AForm *createShrubberyCreationForm(std::string const &target);
        AForm *createRobotomyRequestForm(std::string const &target);
        AForm *createPresidentialPardonForm(std::string const &target);
};

#endif