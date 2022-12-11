/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeGuesser.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:55:21 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/11 14:12:37 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEGUESSER_HPP
# define TYPEGUESSER_HPP

# include <sstream>
# include <iostream>
# include <math.h>
# include <iomanip>
# define SHOW_CONSTRUCTORS 0
# define SHOW_DESTRUCTORS 0

class TypeGuesser
{
	public:
		~TypeGuesser(void);
		TypeGuesser(char* input);
		TypeGuesser(TypeGuesser const& source);
		TypeGuesser & operator=(TypeGuesser & rhs);

		bool	looksLikeInt(void);
		bool	looksLikeFloat(void);
		bool	looksLikeDouble(void);
		bool	looksLikeChar(void);

		// Getters
		float	getFloat(void);
		double	getDouble(void);
		char	getChar(void);
		int		getInt(void);

		// solver
		void	solve(void);
		class IsNotCorrectValue : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	protected:
	private:
		// printers
		void	printChar(char value);
		void	printChar(float value);
		void	printChar(double value);
		void	printChar(int value);

		void	printInt(char value);
		void	printInt(float value);
		void	printInt(double value);
		void	printInt(int value);

		void	printFloat(char value);
		void	printFloat(float value);
		void	printFloat(double value);
		void	printFloat(int value);

		void	printDouble(char value);
		void	printDouble(float value);
		void	printDouble(double value);
		void	printDouble(int value);

		TypeGuesser(void);
		std::stringstream _input;
};

#endif
