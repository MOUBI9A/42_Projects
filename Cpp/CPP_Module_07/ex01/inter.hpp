/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:02:20 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/13 12:05:34 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename Value, typename Function>
void iter(Value *array, int lenth, Function func)
{
    // int i = 0;
    // while(i < lenth)
    // {
    //     func(array[i]);
    //     i++;
    // }
    for(int i = 0;i < lenth; i++)
        func(array[i]);
}


template <typename Value>
void printvalue(const Value &element)
{
    std::cout<< element<<" ";
}



#endif