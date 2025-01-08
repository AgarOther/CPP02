/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:49:37 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/08 12:48:09 by scraeyme         ###   ########.fr       */
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

bool Fixed::operator>(Fixed const &obj)
{
	return (this->toFloat() > obj.toFloat());
}

bool Fixed::operator<(Fixed const &obj)
{
	return (this->toFloat() < obj.toFloat());
}

bool Fixed::operator>=(Fixed const &obj)
{
	return (this->toFloat() >= obj.toFloat());
}

bool Fixed::operator<=(Fixed const &obj)
{
	return (this->toFloat() <= obj.toFloat());
}

bool Fixed::operator==(Fixed const &obj)
{
	return (this->toFloat() == obj.toFloat());
}

bool Fixed::operator!=(Fixed const &obj)
{
	return (this->toFloat() != obj.toFloat());
}

Fixed Fixed::operator+(Fixed const &obj)
{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const &obj)
{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const &obj)
{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const &obj)
{
	return (this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	++*this;
	return (tmp);
}

const Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	--*this;
	return (tmp);
}

const Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed &Fixed::max(Fixed &v1, Fixed &v2)
{
	return (v1 > v2 ? v1 : v2);
}

Fixed &Fixed::min(Fixed &v1, Fixed &v2)
{
	return (v1 < v2 ? v1 : v2);
}

const Fixed &Fixed::max(Fixed const &v1, Fixed const &v2)
{
	return (v1.toFloat() > v2.toFloat() ? v1 : v2);
}

const Fixed &Fixed::min(Fixed const &v1, Fixed const &v2)
{
	return (v1.toFloat() < v2.toFloat() ? v1 : v2);
}
