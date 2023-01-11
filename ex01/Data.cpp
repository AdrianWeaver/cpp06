/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:05:18 by aweaver           #+#    #+#             */
/*   Updated: 2023/01/11 13:44:09 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("unkown"), _age(0)
{
}

Data::Data(Data const & source) : _name(source._name), _age(source._age)
{
}

Data::Data(std::string name, int age) : _name(name), _age(age)
{
}

Data::~Data()
{
}

Data & Data::operator=(Data const & rhs)
{
	this->_age = rhs._age;
	return (*this);
}

void	Data::DisplayData()
{
	std::cout << this->_name << "is " << this->_age << "years old." << std::endl;
}
