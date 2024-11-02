/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:52:39 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/13 12:00:30 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename Value>
void swap(Value &a, Value &b)
{
    Value tmp;
    tmp = a;
    a = b;
    b = tmp;
}


template <typename Value> 
Value max(const Value &a, const Value &b)
{
    if(a > b)
        return a;
    return b;
}

template <typename Value>
Value min(const Value &a, const Value &b)
{
    if(a < b)
        return a;
    return b;
}


#endif