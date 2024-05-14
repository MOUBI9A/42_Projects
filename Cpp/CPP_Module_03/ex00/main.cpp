/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:42 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/10 15:54:45 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main() {
    ClapTrap lgachta("lgachta", 5);

    ClapTrap weld_lgachta("weld_lgachta");


    ClapTrap anis(lgachta);

    while(lgachta.getHitPoints() && weld_lgachta.getHitPoints() && anis.getHitPoints()) 
    {
        lgachta.attack(weld_lgachta);
        weld_lgachta.attack(anis);
        anis.attack(lgachta);
    }
}

    