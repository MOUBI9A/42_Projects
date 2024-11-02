/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:46:56 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/12 15:56:09 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data data;
    data.string = "Hello World!";
    uintptr_t raw = Serialize::serialize(&data);
    std::cout << raw << std::endl;
    Data* ptr = Serialize::deserialize(raw);
    std::cout << ptr->string << std::endl;
    return 0;
}