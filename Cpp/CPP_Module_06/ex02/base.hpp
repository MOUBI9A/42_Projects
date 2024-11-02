/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:59:14 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/12 16:03:43 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base* generate();
void identify(Base* p); 
void identify(Base& p); 

#endif