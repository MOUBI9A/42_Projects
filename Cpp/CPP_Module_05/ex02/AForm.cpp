/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:52:56 by hel-moue          #+#    #+#             */
/*   Updated: 2024/09/25 08:26:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Form"), sign(false), NeedtoSign(1), NeedtoExct(1)
{}


AForm::AForm(std::string const name, int const NeedtoSign, int const NeedtoExct) : name(name), sign(false), NeedtoSign(NeedtoSign), NeedtoExct(NeedtoExct)
{
    if (NeedtoSign < 1 || NeedtoExct < 1)
        throw AForm::GradeTooHighException();
    if (NeedtoSign > 150 || NeedtoExct > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : name(src.name), sign(src.sign), NeedtoSign(src.NeedtoSign), NeedtoExct(src.NeedtoExct)
{
    *this = src;
}

AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
        this->sign = src.sign;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return name;
}


bool AForm::getSign() const
{
    return sign;
}

void AForm::TrueSign()
{
    sign = true;
}

int AForm::getToSign() const
{
    return NeedtoSign;
}

int AForm::getToExct() const
{
    return NeedtoExct;
}


void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > NeedtoSign)
        throw AForm::GradeTooLowException();
    sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, AForm &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSign())
        out << "signed" << std::endl;
    else
        out << "not signed" << " and grade to be signe is " << form.getToSign() << std::endl;
    return out;
}
