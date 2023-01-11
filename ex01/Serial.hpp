/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:17:45 by aweaver           #+#    #+#             */
/*   Updated: 2023/01/11 12:27:10 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIAL_HPP
# define SERIAL_HPP

#include <stdint.h>
uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
