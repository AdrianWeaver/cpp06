/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:24:17 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/08 20:03:52 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please provide only one arg" << std::endl;
		return (0);
	}
	std::string	input;

	input = static_cast<std::string>(argv[1]);
	std::cout << "Niktamaire le argv" << std::endl << input << std::endl;
	bool		comma = 0;
	bool		isFloat = 0;
	bool		isString;
	for (unsigned int i = 0; i < strlen(argv[1]); i++)
	{
		if (isalpha(argv[1][i]) || isspace(argv[1][i]))
		{
			isString = 1;
			break ;
		}
		if (!isdigit(argv[1][i]))
		{
			if (i == strlen(argv[1]) && argv[1][i] == 'f')
				isFloat = 1;
			if (i != 0 && argv[1][i] == '.' && comma == 0)
				comma = 1;
			else if (i == 0 && (!(argv[1][i] == '+' || argv[1][i] == '-')))
			{
				isString = 1;
				break;
			}
			else if (comma == 1 && argv[1][i] == '.')
			{
				isString = 1;
				break;
			}
		}
	}
	if (isString == 1)
		std::cout << "This is a string I'm sure of it!" << std::endl;
	else if (comma == 1 && isFloat == 1)
		std::cout << "This is a float I'm sure of it!" << std::endl;
	else if (comma == 1 && isFloat == 0)
		std::cout << "This is a double I'm sure of it!"  << std::endl;
	else
		std::cout << "This is an int I'm sure of it!" << std::endl;

}
