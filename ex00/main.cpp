/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:24:17 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/11 15:19:49 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstring>
#include "TypeGuesser.hpp"
#include <iomanip>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please provide only one arg" << std::endl;
		return (0);
	}
	TypeGuesser		typeGuesser(argv[1]);
	std::stringstream sstest(argv[1]);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	typeGuesser.solve();
	return (0);
}
