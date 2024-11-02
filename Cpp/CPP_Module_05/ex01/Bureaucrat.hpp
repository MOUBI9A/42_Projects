/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/09/25 06:54:49 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string	name;
        int					grade;
        int                 timeofwork;
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
        void work();
        void party();
        void signForm(Form &form);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);
#endif