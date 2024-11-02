/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:02:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{
    private:
        const std::string	name;
        int					grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        Bureaucrat	&operator=(const Bureaucrat &bureaucrat);


        const std::string& getName();
        int getGrade();
        
        void setGrade(int newGrade);


        void addGrade();
        void subGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
}; // Bureaucrat_HPP

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
