/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:31:46 by axcallet          #+#    #+#             */
/*   Updated: 2023/12/11 14:32:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) {
	this->_maxNumber = N;
	return ;
}

Span::Span(const Span &toCopy) {
	*this = toCopy;
	return ;
}

// Destructor
Span::~Span(void) {
	return ;
}

// Overload operator
Span	&Span::operator=(const Span &toCopy) {
	if (this == &toCopy)
		return (*this);
	this->_maxNumber = toCopy._maxNumber;
	return (*this);
}

// Public methods
int	Span::shortestSpan(void) {
	int		smaller;
	int		len = this->_array.size();

	if (this->_array.size() == 0 || this->_array.size() == 1)
		throw NotEnoughNumbersException();
	std::sort(this->_array.begin(), this->_array.end());
	smaller = this->_array[1] - this->_array[0];
	for (int i = 1; i < len - 1; i++) {
		int tmpSmaller = this->_array[i + 1] - this->_array[i];
		if (tmpSmaller < smaller)
			smaller = tmpSmaller;
	}
	return (smaller);
}

int	Span::longestSpan(void) {
	int		len = this->_array.size();

	if (this->_array.size() == 0 || this->_array.size() == 1)
		throw NotEnoughNumbersException();
	std::sort(this->_array.begin(), this->_array.end());
	return (this->_array[len - 1] - this->_array[0]);
}

void	Span::addNumber(int newNumber) {
	if (this->_array.size() == this->_maxNumber)
		throw ToMuchNumbersException();
	this->_array.push_back(newNumber);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_array.size() + std::distance(begin, end) > this->_maxNumber)
		throw ToMuchNumbersException();
	this->_array.insert(this->_array.end(), begin, end);
	return ;
}


// Exceptions
const char	*Span::ToMuchNumbersException::what(void) const throw() {
	return ("There is already the maximum number of integers");
}

const char	*Span::NotEnoughNumbersException::what(void) const throw() {
	return ("Not enough numbers");
}
