/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:27:32 by axcallet          #+#    #+#             */
/*   Updated: 2023/12/04 11:37:06 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "\n### MANDATORY TEST ###\n" << _END << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << _BLUE << "\n### SPAN TESTS ###\n" << _END << std::endl;
		try {
			int					array[7] = {0, 2, 4, 6, 8, 10, 54};
			Span				span(10);
			std::vector<int>	itArray(array, array + 7);

			span.addNumber(55);
			span.addNumber(-99);
			span.addNumber(100);
			span.addNumbers(itArray.begin(), itArray.end());
			
			std::cout << _GREEN << span.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << span.longestSpan() << _END << std::endl;
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### EXCEPTION TESTS ###\n" << _END << std::endl;
		try {
			Span	span(3);

			span.addNumber(42);
			span.addNumber(69);
			span.addNumber(8);
			span.addNumber(13);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		try {
			int					array[5] = {12, 56, 478, -62, 99};
			Span				span(10);
			std::vector<int>	itArray(array, array + 5);
			
			span.addNumber(8);
			span.addNumber(5687);
			span.addNumber(3);
			span.addNumber(-745);
			span.addNumber(23);
			span.addNumber(895);
			span.addNumbers(itArray.begin(), itArray.end());
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		try {
			Span	span(3);

			std::cout << _GREEN << span.shortestSpan() << _END << std::endl;
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		try {
			Span	span(1);

			span.addNumber(8);
			std::cout << _GREEN << span.longestSpan() << _END << std::endl;
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}