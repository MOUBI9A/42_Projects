/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:58:58 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/12 16:03:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

Base::~Base()
{
    std::cout << "deconstructor called" << std::endl;
}

Base* generate()
{
    int i;
    srand((unsigned)time(0));
    i = (rand()%3)+1;
    // std::cout << "i = " << i << std::endl;
    // exit(0);
    switch(i)
    {
        case 1:
            return new A();
        case 2:
            return new B();
        case 3:
            return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}