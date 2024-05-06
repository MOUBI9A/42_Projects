/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:30 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/28 20:09:31 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

size_t Change(std::string& file_content, std::string s1, std::string s2)
{
	std::string new_content;
	size_t find_pos;
	size_t i = 0;

	find_pos = file_content.find(s1);
	while(find_pos < file_content.length())
	{
		i++;
		file_content.erase(find_pos, s1.length());
		file_content.insert(find_pos, s2);
		find_pos = file_content.find(s1);
	}
	return (i);
}

int main(int ac, char **av)
{
	std::string file_content;

	if (ac != 4)
		std::cout << "\033[1;31mError : Bad Usage\033[0m" << std::endl;
	else
	{
		file_content = av[1];
		std::string newfile = file_content;
		if (newfile.find(".") != std::string::npos)
		{
			std::cout << "\033[1;34mDo you want to replace the file extension ? (y/n)\033[0m" << std::endl;
			std::string input;
			std::cin >> input;
			if(input == "y")
				newfile.erase(newfile.find("."), newfile.length());
		}
		newfile += ".replace";
		std::ifstream file(file_content);
		if (file.is_open())
		{
			std::ofstream replace_file;
			replace_file.open(newfile, std::ios::out);
			if(!replace_file.is_open())
			{
				file.close();
				std::cout << "\033[1;31mError In Creating File\033[0m" << std::endl;
				return (0);
			}
			std::cout << "\033[1;34mNew file name : " << newfile << "\033[0m" << std::endl;
			size_t Nb_Replace = 0;
			while (getline(file, file_content))
			{
				Nb_Replace = Nb_Replace + Change(file_content, av[2], av[3]);
				replace_file << file_content;
				if (!file.eof())
					replace_file << "\n";
			}
			file.close();
			replace_file.close();
			std::cout << "\033[1;32mbedeti "<< Nb_Replace << " Mera " << av[2] << " Men "<< av[1] << " l file jdid smito " << newfile <<"\nReplacements Done\033[0m" << std::endl;
		}
		else
			std::cout << "\033[1;31m Error : File Not Found \033[0m" << std::endl;
	}
	return (0);
}
