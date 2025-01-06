/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:49:37 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/06 18:03:41 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	this->setRawBits(copy.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	this->setRawBits(obj.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed::Fixed(const float value)
{
	this->_value = (int)roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << this->_bits);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
	std::cout << obj.toFloat();
	return (os);
}
