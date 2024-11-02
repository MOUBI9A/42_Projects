/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:25:46 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:35:35 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include<iostream>
#include"AForm.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &ref);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &ref);
        ~PresidentialPardonForm();
        
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
};

