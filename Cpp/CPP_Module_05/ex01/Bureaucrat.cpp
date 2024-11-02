/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/09/25 06:54:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Lmowatin"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this == &bureaucrat)
        return *this;
    grade = bureaucrat.grade;
    return *this;
}

const std::string& Bureaucrat::getName() {
    return name;
}

int Bureaucrat::getGrade() {
    return grade;
}

void Bureaucrat::setGrade(int newGrade) {
    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = newGrade;
}

void Bureaucrat::addGrade() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::subGrade() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
        grade++;
}

// void Bureaucrat::work() 
// {
//     // std::cout << "Bureaucrat " << name << " is working" << std::endl;
//     timeofwork++;
//     if (timeofwork >= 5)
//     {
//         timeofwork = 0;
//         setGrade(grade - 5);
//         std::cout << "Bonus for " << name << " 5 levels up {" << grade << "}" << std::endl;
//     }
//     else
//         addGrade();
// }

void Bureaucrat::work() 
{
    timeofwork++;
    std::cout << "Bureaucrat " << name << " is working" << std::endl;
    addGrade();

}

void Bureaucrat::party() 
{
    std::cout << "Bureaucrat " << name << " is partying" << std::endl;
    timeofwork = 0;
    subGrade();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        if (grade > form.getToSign())
            throw Bureaucrat::GradeTooLowException();
        form.TrueSign();
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}