/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:11 by ybourais          #+#    #+#             */
/*   Updated: 2024/10/12 14:07:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"

#include <sstream> 
#include <iomanip>  
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <sstream>


ScalarConverte::ScalarConverte()
{
    std::cout<< "default constructor called"<<std::endl;
    // this->i++;
}

ScalarConverte::~ScalarConverte()
{
    std::cout<< "deconstracter called"<< std::endl;
}

void ScalarConverte::convert(const std::string str)
{
    // to char
    std::istringstream issChar(str);
    int charInt;
    if (issChar >> charInt) 
    {
        if (isprint(charInt))
        {
            char c = static_cast<char>(charInt);
            std::cout << "char: " << c << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    // to int
    std::string strInt = str;
    if (strInt.back() == 'f' || strInt.back() == 'F')
        strInt.pop_back();
    std::istringstream issInt(strInt);
    int i;
    if (issInt >> i)
        std::cout << "int: " << i << std::endl; 
    else
        std::cout << "int: impossible" << std::endl;

    // to float
    std::string strFloat = str;
    if (strFloat.back() == 'f' || strFloat.back() == 'F')
        strFloat.pop_back();
    std::istringstream issFloat(strFloat);
    float f;
    if (issFloat >> f)
    {
        std::cout << "float: ";
        if (f == floorf(f) && !isinf(f))
            std::cout << f << ".0f";
        else 
            std::cout << f << "f";
        std::cout << std::endl;
    } 
    else
        std::cout << "float: impossible" << std::endl;

    // to double
    std::string strDouble = str;
    if (strDouble.back() == 'f' || strDouble.back() == 'F')
        strDouble.pop_back();
    std::istringstream issDouble(strDouble);
    double d;
    if (issDouble >> d)
    {
        std::cout << "double: ";
        if (d == floor(d) && !isinf(d))
            std::cout << d << ".0";
        else 
            std::cout << d;
        std::cout << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}