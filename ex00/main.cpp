/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:51:28 by axcallet          #+#    #+#             */
/*   Updated: 2023/12/04 11:28:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "\n### TESTS WITH VECTOR ###\n" << _END << std::endl;
		try {
			std::vector<int> myVector;

			myVector.push_back(4);
			myVector.push_back(87);
			myVector.push_back(786950);
			myVector.push_back(7894);
			myVector.push_back(-5);
			easyfind(myVector, 7894);
			easyfind(myVector, 3);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS WITH LIST ###\n" << _END << std::endl;
		try {
			std::list<int> myList;

			myList.push_back(87);
			myList.push_back(-72);
			myList.push_back(-5);
			myList.push_back(69);
			myList.push_back(18);
			easyfind(myList, -72);
			easyfind(myList, 3);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	return (0);
}