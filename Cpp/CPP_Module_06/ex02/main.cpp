/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:59:21 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/12 16:02:33 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}