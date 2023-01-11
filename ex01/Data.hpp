/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:01:28 by aweaver           #+#    #+#             */
/*   Updated: 2023/01/11 12:24:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data
{
	public:
		Data();
		Data(std::string name, int age);
		Data(Data const& source);
		Data & operator=(Data const & rhs);
		void	DisplayData();
	protected:
	private:
		const std::string _name;
		int			_age;
};

#endif
