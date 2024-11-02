/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:08:50 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:08:51 by hel-moue         ###   ########.fr       */
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
	std::string Choices[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	while (++i < 4)
	{
		if (argv[1] == Choices[i])
			break;
	}
	switch (i)
	{
		case 0:
			while (i < 4)
			{
				std::cout << "[ " << Choices[i] << " ]" << std::endl;
				harl.Complain(Choices[i]);
				std::cout << std::endl;
				i++;
			}
			break;
		case 1:
			while (i < 4)
			{
				std::cout << "[ " << Choices[i] << " ]" << std::endl;
				harl.Complain(Choices[i]);
				std::cout << std::endl;
				i++;
			}
			break;
		case 2:
			while (i < 4)
			{
				std::cout << "[ " << Choices[i] << " ]" << std::endl;
				harl.Complain(Choices[i]);
				std::cout << std::endl;
				i++;
			}
			break;
		case 3:
			while (i < 4)
			{
				std::cout << "[ " << Choices[i] << " ]" << std::endl;
				harl.Complain(Choices[i]);
				std::cout << std::endl;
				i++;
			}
			break;
		default:
			std::cout << "Usage: ./harl_2_0 [DEBUG, INFO, WARNING, ERROR]" << std::endl;
			return (1);
	}


	return (0);
}