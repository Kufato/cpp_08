/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:51:59 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/22 11:45:33 by axcallet         ###   ########.fr       */
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

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

class	OccurenceExecption : public std::exception {
	virtual const char	*what(void) const throw() {
		return ("There are no occurrences in this container");
	};
};

template <class T>
void	easyfind(T &container, int toFind) {
	typename T::iterator	it = std::find(container.begin(), container.end(), toFind);
	if (it != container.end())
		std::cout << "Première occurrence de " << toFind << " trouvée à l'index : "
				<< std::distance(container.begin(), it) << std::endl;
	else
		throw ::OccurenceExecption();
	return ;
}
