/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:09 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/08 12:54:51 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// My tests
	std::cout << std::endl;
	std::cout << "a is: " << a << "  b is: " << b << std::endl;
	std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
	std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
	std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
	std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
	std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;

	std::cout << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;

	std::cout << std::endl;
	std::cout << "a++: " << a++;
	std::cout << "| value after: " << a << std::endl;
	std::cout << "++a: " << ++a;
	std::cout << "| value after: " << a << std::endl;
	std::cout << "a--: " << a--;
	std::cout << "| value after: " << a << std::endl;
	std::cout << "--a: " << --a;
	std::cout << "| value after: " << a << std::endl;

	return 0;
}
