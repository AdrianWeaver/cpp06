/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:11:15 by aweaver           #+#    #+#             */
/*   Updated: 2023/01/11 12:26:50 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serial.hpp"

int	main()
{
	Data myMate("MaMate", 30);
	uintptr_t myMateSerialised;
	Data* myMateDeserialised;

	std::cout << &myMate << std::endl;
	myMateSerialised = serialize(&myMate);
	myMateDeserialised = deserialize(myMateSerialised);
	std::cout << myMateDeserialised << std::endl;
	return (0);
}
