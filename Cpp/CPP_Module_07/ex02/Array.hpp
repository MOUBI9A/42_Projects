/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:11:40 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/13 12:32:41 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename Value>
class Array
{
    private:
        Value *data;
        unsigned int arraySize;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(Array<Value> &copy);
        Array &operator=(Array<Value> &src);
        Value& operator[](unsigned int index); 
        
        unsigned int size() const;
};

template <typename Value>
Array<Value>::Array()
{
    std::cout << "Array constructor called" << std::endl;
    this->data = new Value();
    arraySize = 0;
}

template <typename Value>
Array<Value>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete[] data;
}


template <typename Value>
Array<Value>::Array(unsigned int n)
{
    std::cout << "Array constructor called" << std::endl;
    this->data = new Value[n];
    arraySize = n;
}

template <typename Value>
Array<Value>::Array(Array <Value> &copy)
{
    std::cout << "Array constructor called" << std::endl;
    data = new Value[copy.size()]; 
    for(unsigned int i = 0;i < copy.size();i++)
        data[i] = copy.data[i];
    arraySize = copy.arraySize;
}

template <typename Value>
Array<Value> &Array<Value>::operator=(Array<Value> &src)
{
    std::cout << "Array operator= called" << std::endl;
    if(this != &src)
    {
        if(this->data)
            delete[] data;
        data = new Value[src.size()];
        for(unsigned int i = 0;i < src.size();i++)
            data[i] = src.data[i];
        arraySize = src.arraySize;
    }
    return *this;
}

template <typename Value>
unsigned int Array<Value>::size() const
{
    // std::cout << "Array size called" << std::endl;
    return (arraySize);
}

template <typename Value>
Value &Array<Value>::operator[](unsigned int index) 
{
    // std::cout << "Array operator[] called" << std::endl;
    if (index >= size()) 
        throw std::out_of_range("Index out of bounds");
    return data[index];
}



#endif