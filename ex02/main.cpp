/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:48:50 by aweaver           #+#    #+#             */
/*   Updated: 2023/01/11 14:33:14 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

Base*	generate(void)
{
	int rng = rand() % 3;

	switch (rng)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is of type A." << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is of type B." << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is of type C." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A type = dynamic_cast<A&>(p);
			std::cout << "pointer is of type A." << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B type = dynamic_cast<B&>(p);
			std::cout << "pointer is of type B." << std::endl;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		C type = dynamic_cast<C&>(p);
			std::cout << "pointer is of type C." << std::endl;
	}
	catch(std::exception &e)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base *created;

	created = generate();
	identify(created);
	identify(*created);
	return (0);
}
