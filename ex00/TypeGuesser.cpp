/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeGuesser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:12:46 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/11 15:24:23 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeGuesser.hpp"

TypeGuesser::TypeGuesser(void)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << "This is the default TypeGuesser constructor" << std::endl;
}

TypeGuesser::~TypeGuesser(void)
{
	if (SHOW_DESTRUCTORS)
		std::cout << "This is the default TypeGuesser destructor" << std::endl;
}

TypeGuesser::TypeGuesser(char *input) : _input(input)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << "This is the default TypeGuesser constructor" << std::endl;
}

bool TypeGuesser::looksLikeInt(void)
{
	int			asInt;
	std::string	inputChecker;

	this->_input.clear();
	this->_input >> asInt;
	if (this->_input.eof() && !this->_input.fail())
	{
		this->_input.seekg(0);
		return (true);
	}
	this->_input.seekg(0);
	return (false);
}

bool TypeGuesser::looksLikeFloat(void)
{
	float		asFloat;
	std::string	inputChecker;

	getline(this->_input, inputChecker);
	this->_input.clear();
	this->_input.seekg(0);
	if (inputChecker == "nanf" || inputChecker == "-inff"
			|| inputChecker == "inff")
		return (true);
	this->_input >> asFloat >> inputChecker;
	if (this->_input.eof() && !this->_input.fail() && inputChecker == "f")
	{
		this->_input.clear();
		this->_input.seekg(0);
		return (true);
	}
	this->_input.clear();
	this->_input.seekg(0);
	return (false);
}

bool TypeGuesser::looksLikeDouble(void)
{
	double		asDouble;
	std::string	inputChecker;

	getline(this->_input, inputChecker);
	this->_input.clear();
	this->_input.seekg(0);
	if (inputChecker == "nan" || inputChecker == "-inf"
			|| inputChecker == "inf")
		return (true);
	this->_input >> asDouble;
	if (this->_input.eof() && !this->_input.fail())
	{
		this->_input.clear();
		this->_input.seekg(0);
		return (true);
	}
	this->_input.clear();
	this->_input.seekg(0);
	return (false);
}

bool TypeGuesser::looksLikeChar(void)
{
	std::string	inputChecker;

	this->_input >> inputChecker;
	if (inputChecker.size() == 1 && !this->_input.fail())
	{
		this->_input.clear();
		this->_input.seekg(0);
		return (true);
	}
	this->_input.clear();
	this->_input.seekg(0);
	return (false);
}

const char* TypeGuesser::IsNotCorrectValue::what(void) const throw()
{
	return ("Trying to get from an invalid type");
}

float TypeGuesser::getFloat(void)
{
	std::string	inputChecker;
	float		ret;
	this->_input >> inputChecker;
	this->_input.clear();
	this->_input.seekg(0);
	if (inputChecker == "nanf")
		return (NAN);
	else if (inputChecker == "inff")
		return (INFINITY);
	else if (inputChecker == "-inff")
		return (-INFINITY);
	if (this->looksLikeFloat() == false)
		throw IsNotCorrectValue();
	this->_input >> ret;
	this->_input.clear();
	this->_input.seekg(0);
	return (ret);
}

int TypeGuesser::getInt(void)
{
	int	ret;
	if (this->looksLikeInt() == false)
		throw IsNotCorrectValue();
	this->_input >> ret;
	this->_input.clear();
	this->_input.seekg(0);
	return (ret);
}

double TypeGuesser::getDouble(void)
{
	double	ret;
	if (this->looksLikeDouble() == false)
		throw IsNotCorrectValue();
	this->_input >> ret;
	this->_input.clear();
	this->_input.seekg(0);
	return (ret);
}

char TypeGuesser::getChar(void)
{
	char	ret;
	if (this->looksLikeChar() == false)
		throw IsNotCorrectValue();
	this->_input >> ret;
	this->_input.clear();
	this->_input.seekg(0);
	return (ret);
}

void	TypeGuesser::printChar(char value)
{
	if (isprint(value))
		std::cout << "char: " << value << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;
}

void	TypeGuesser::printChar(float value)
{
	if (value != value || value == INFINITY || value == -INFINITY)
		std::cout << "char: impossible." << std::endl;
	else
		this->printChar(static_cast<char>(value));
}

void	TypeGuesser::printChar(double value)
{
	if (value != value || value == INFINITY || value == -INFINITY)
		std::cout << "char: impossible." << std::endl;
	else
		this->printChar(static_cast<char>(value));
}

void	TypeGuesser::printChar(int value)
{
	if (isprint(value))
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;

}

void	TypeGuesser::printFloat(char value)
{
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void	TypeGuesser::printFloat(int value)
{
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void	TypeGuesser::printFloat(float value)
{
	std::cout << "float: " << value << "f" << std::endl;
}

void	TypeGuesser::printFloat(double value)
{
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void	TypeGuesser::printDouble(double value)
{
	std::cout << "double: " << value << std::endl;
}

void	TypeGuesser::printDouble(float value)
{
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	TypeGuesser::printDouble(char value)
{
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	TypeGuesser::printDouble(int value)
{
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	TypeGuesser::printInt(char value)
{
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	TypeGuesser::printInt(float value)
{
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	TypeGuesser::printInt(double value)
{
	std::cout << "int: " << static_cast<double>(value) << std::endl;
}

void	TypeGuesser::printInt(int value)
{
	std::cout << "int: " << value << std::endl;
}

void	TypeGuesser::solve(void)
{
	int		asInt;
	float	asFloat;
	double	asDouble;
	char	asChar;
	if (this->looksLikeFloat() == true)
	{
		asFloat = this->getFloat();
		asInt = static_cast<int>(asFloat);
		asDouble = static_cast<double>(asFloat);
		asChar = static_cast<char>(asFloat);
		this->printChar(asFloat);
		this->printInt(asFloat);
		this->printFloat(asFloat);
		this->printDouble(asFloat);
	}
	else if (this->looksLikeInt() == true)
	{
		asInt = this->getInt();
		asFloat = static_cast<float>(asInt);
		asDouble = static_cast<double>(asInt);
		asChar = static_cast<char>(asInt);
		this->printChar(asInt);
		this->printInt(asInt);
		this->printFloat(asInt);
		this->printDouble(asInt);
	}
	else if (this->looksLikeDouble() == true)
	{
		asDouble = this->getDouble();
		asInt = static_cast<int>(asDouble);
		asFloat = static_cast<float>(asDouble);
		asChar = static_cast<char>(asDouble);
		this->printChar(asDouble);
		this->printInt(asDouble);
		this->printFloat(asDouble);
		this->printDouble(asDouble);
	}
	else if (this->looksLikeChar() == true)
	{
		asChar = this->getChar();
		asInt = static_cast<int>(asChar);
		asDouble = static_cast<double>(asChar);
		asChar = static_cast<char>(asChar);
		this->printChar(asChar);
		this->printInt(asChar);
		this->printFloat(asChar);
		this->printDouble(asChar);
	}
	else
		std::cout << "Input given does not make sense, cannot convert!" << std::endl;
}
