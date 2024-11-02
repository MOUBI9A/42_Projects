/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:10:17 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:18 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "string address    : " << &str <<std::endl;
	std::cout << "stringPTR address : " << stringPTR <<std::endl;
	std::cout << "stringREF address : " << &stringREF <<std::endl;

	std::cout << "stringPTR value   : " << *stringPTR <<std::endl;
	std::cout << "stringREF value   : " << stringREF <<std::endl;
}