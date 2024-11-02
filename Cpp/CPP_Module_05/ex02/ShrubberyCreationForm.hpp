/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:52:56 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/11 11:39:35 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include<iostream>
#include"AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm();
        
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
};

