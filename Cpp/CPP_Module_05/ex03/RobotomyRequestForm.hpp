/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 07:26:23 by hel-moue          #+#    #+#             */
/*   Updated: 2024/09/27 02:29:58 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<iostream>
#include"AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &ref);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
};

