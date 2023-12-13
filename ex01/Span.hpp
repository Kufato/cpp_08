/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:31:50 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/23 11:15:13 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

class	Span {
	
	private:
		Span(void);
		unsigned int		_maxNumber;
		std::vector<int>	_array;

	public:
	// Constructors
		Span(unsigned int N);
		Span(const Span &toCopy);

	// Destructor
		~Span(void);

	// Overload operator
		Span &operator=(const Span &toCopy);

	// Public methods
		int		longestSpan(void);
		int		shortestSpan(void);
		void	addNumber(int newNumber);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	// Exceptions
	class	ToMuchNumbersException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class	NotEnoughNumbersException : public std::exception {
		virtual const char	*what(void) const throw();
	};
};
