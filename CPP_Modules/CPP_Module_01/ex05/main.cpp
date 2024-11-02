/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:08:53 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// int main(void)
// {
// 	Harl harl;
// 	harl.Complain("DEBUG");
// 	harl.Complain("INFO");
// 	harl.Complain("WARNING");
// 	harl.Complain("ERROR");
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harl_2_0 [DEBUG, INFO, WARNING, ERROR]" << std::endl;
		return (1);
	}
	Harl harl;
	harl.Complain(argv[1]);
	return (0);
}