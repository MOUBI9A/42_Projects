/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:15:00 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/14 19:20:06 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>

class PhoneBook
{
    private :
        Contact Contacts[8];
        unsigned int nb_contacts;
    public :
        PhoneBook();
        void Start();
        std::string command;
        std::string Get_10(std::string str);
        void ADD_CONTACT(Contact &Contact);
        void ADD_FIRST_NAME(Contact &Contact);
        void ADD_LAST_NAME(Contact &Contact);
        void ADD_NICK_NAME(Contact &Contact);
        void ADD_PHONE_NUMBER(Contact &Contact);
        void ADD_DARCKEST_SECRET(Contact &Contact);
        void PRINT_CONTACTS();
        void PRINT_CONTACT(std::string str);
        void SEARCH();
        void EXIT();
};

#endif