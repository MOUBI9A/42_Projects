/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:15:08 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/14 19:18:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string PhoneBook::Get_10(std::string str)
{
    if(str.length() <= 10)
        return str;
    std::string s = str.substr(0,9);
    s = s + ".";
    return s;
}

void PhoneBook::ADD_FIRST_NAME(Contact &Contacts)
{
    std::cout << "Enter the \033[35mfirst name\033[0m :\n";
    std::getline(std::cin, command);
    if (std::cin.eof())
        EXIT();
    int flag = 0;
    for (unsigned int i = 0; i < command.length(); i++)
    {
        if ((command[i] < 'A' || command[i] > 'Z') && (command[i] < 'a' || command[i] > 'z'))
        {
            flag = 1;
            break;
        }
    }
    if (command.empty() || command == " " || command == "\t" || flag)
    {
        std::cout << "\033[31mError\033[0m : \033[35minvalid first name\033[0m\n";
        ADD_FIRST_NAME(Contacts);
    }
    Contacts.set_first_name(command);
}

void PhoneBook::ADD_LAST_NAME(Contact &Contacts)
{
    std::cout << "Enter the \033[35mlast name\033[0m :\n";
    std::getline(std::cin, command);
    if (std::cin.eof())
        EXIT();
    int flag = 0;
    for (unsigned int i = 0; i < command.length(); i++)
    {
        if ((command[i] < 'A' || command[i] > 'Z') && (command[i] < 'a' || command[i] > 'z'))
        {
            flag = 1;
            break;
        }
    }
    if (command.empty() || command == " " || command == "\t" || flag)
    {
        std::cout << "\033[31mError\033[0m : \033[35minvalid last name\033[0m\n";
        ADD_LAST_NAME(Contacts);
    }
    Contacts.set_last_name(command);
}

void PhoneBook::ADD_NICK_NAME(Contact &Contacts)
{
    std::cout << "Enter the \033[35mnick name\033[0m :\n";
    std::getline(std::cin, command);
    if (std::cin.eof())
        EXIT();
    int flag = 0;
    for (unsigned int i = 0; i < command.length(); i++)
    {
        if ((command[i] < 'A' || command[i] > 'Z') && (command[i] < 'a' || command[i] > 'z'))
        {
            flag = 1;
            break;
        }
    }
    if (command.empty() || command == " " || command == "\t" || flag)
    {
        std::cout << "\033[31mError\033[0m : \033[35minvalid nick name\033[0m\n";
        ADD_NICK_NAME(Contacts);
    }
    Contacts.set_nick_name(command);
}

void PhoneBook::ADD_PHONE_NUMBER(Contact &Contacts)
{
    std::cout << "Enter the \033[35mphone number\033[0m :\n";
    std::getline(std::cin, command);
    if (std::cin.eof())
        EXIT();
    int flag = 0;
    for (unsigned int i = 0; i < command.length(); i++)
    {
        if (command[i] < '0' || command[i] > '9')
        {
            flag = 1;
            break;
        }
    }
    if (command.empty() || command == " " || command == "\t" || flag)
    {
        std::cout << "\033[31mError\033[0m : \033[35minvalid phone number\033[0m\n";
        ADD_PHONE_NUMBER(Contacts);
    }
    Contacts.set_phone_number(command);
}

void PhoneBook::ADD_DARCKEST_SECRET(Contact &Contacts)
{
    std::cout << "Enter the \033[35mdarkest secret\033[0m :\n";
    std::getline(std::cin, command);
    if (std::cin.eof())
        EXIT();
    Contacts.set_darckest_secret(command);
}