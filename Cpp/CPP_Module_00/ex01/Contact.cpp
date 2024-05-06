/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:14:44 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/14 19:31:09 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

void Contact::set_first_name(std::string f)
{
    this->first_name = f;
}

void Contact::set_last_name(std::string l)
{
    this->last_name = l;
}

void Contact::set_phone_number(std::string p)
{
    this->phone_number = p;
}

void Contact::set_nick_name(std::string n)
{
    this->nick_name = n;
}

void Contact::set_darckest_secret(std::string ds)
{
    this->darckest_secret = ds;
}

std::string Contact::get_first_name()
{
    return (this->first_name);
}

std::string Contact::get_last_name()
{
    return (this->last_name);
}

std::string Contact::get_phone_number()
{
    return (this->phone_number);
}

std::string Contact::get_nick_name()
{
    return (this->nick_name);
}

std::string Contact::get_darckest_secret()
{
    return (this->darckest_secret);
}
 