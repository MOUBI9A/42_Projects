/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:14:48 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/14 01:14:49 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include<string>
#include<iostream>

class Contact
{
    private :
    
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darckest_secret;
    public :
    
        void set_first_name(std::string f);
        void set_last_name(std::string l);
        void set_phone_number(std::string p);
        void set_nick_name(std::string n);
        void set_darckest_secret(std::string ds);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_phone_number();
        std::string get_nick_name();
        std::string get_darckest_secret();
};

#endif