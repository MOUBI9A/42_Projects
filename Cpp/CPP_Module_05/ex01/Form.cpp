/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:52:56 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:26:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), sign(false), NeedtoSign(1), NeedtoExct(1)
{
}

Form::Form(std::string const name, int const NeedtoSign, int const NeedtoExct) : name(name), sign(false), NeedtoSign(NeedtoSign), NeedtoExct(NeedtoExct)
{
    if (NeedtoSign < 1 || NeedtoExct < 1)
        throw Form::GradeTooHighException();
    if (NeedtoSign > 150 || NeedtoExct > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : name(src.name), sign(src.sign), NeedtoSign(src.NeedtoSign), NeedtoExct(src.NeedtoExct)
{
    *this = src;
}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
        this->sign = src.sign;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return name;
}


bool Form::getSign() const
{
    return sign;
}

void Form::TrueSign()
{
    sign = true;
}

int Form::getToSign() const
{
    return NeedtoSign;
}

int Form::getToExct() const
{
    return NeedtoExct;
}


void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > NeedtoSign)
        throw Form::GradeTooLowException();
    sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSign())
        out << "signed" << std::endl;
    else
        out << "not signed" << " and grade to be signe is " << form.getToSign() << std::endl;
    return out;
}