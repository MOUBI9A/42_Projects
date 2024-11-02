/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:04:05 by amezioun          #+#    #+#             */
/*   Updated: 2024/10/11 12:17:57 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool sign;
        int const NeedtoSign;
        int const NeedtoExct;
    public:
        AForm();
        AForm(std::string const name, int const NeedtoSign, int const NeedtoExct);
        AForm(AForm const &src);
        AForm &operator=(AForm const &src);
        virtual ~AForm();
        
        std::string getName() const;
        
        bool getSign() const;
        void TrueSign();
        
        
        int getToSign() const;
        
        int getToExct() const;
        
        void beSigned(Bureaucrat &bureaucrat);
        void signForm();


        virtual void execute(Bureaucrat const &executor) const = 0;
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm &form);
