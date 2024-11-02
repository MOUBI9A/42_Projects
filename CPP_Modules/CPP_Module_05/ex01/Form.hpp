/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:04:05 by amezioun          #+#    #+#             */
/*   Updated: 2024/10/11 11:16:33 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool sign;
        int const NeedtoSign;
        int const NeedtoExct;
    public:
        Form();
        Form(std::string const name, int const NeedtoSign, int const NeedtoExct);
        Form(Form const &src);
        Form &operator=(Form const &src);
        ~Form();
        
        std::string getName() const;

        
        
        bool getSign() const;
        void TrueSign();
        
        
        int getToSign() const;
        
        int getToExct() const;
        
        void beSigned(Bureaucrat &bureaucrat);
        void signForm();
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

std::ostream &operator<<(std::ostream &out, Form &form);

#endif