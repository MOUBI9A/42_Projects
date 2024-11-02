/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:00 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:01 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <unistd.h>
int main()
{
    Weapon ak47 = Weapon("AK-47");
    HumanA bob("Bob", ak47);
    HumanB jim("Jim");
    while (bob.checkHP() && jim.checkHP())
    {
        jim.attack(bob);
        std::cout << "\033[1;32mBob's HP: " << bob.getHP() << std::endl;
        usleep(5030000);
        bob.attack(jim);
        std::cout << "\033[1;32mJim's HP: " << jim.getHP() << std::endl;
        usleep(5030000);
    }
    if (bob.checkHP())
        std::cout << "\033[1;32mBob won!" << std::endl;
    else
        std::cout << "\033[1;32mJim won!" << std::endl;
    return 0;
}
