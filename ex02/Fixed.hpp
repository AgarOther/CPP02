/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:49:33 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/08 12:21:09 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(Fixed const &obj);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

		bool operator>(Fixed const &obj);
		bool operator<(Fixed const &obj);
		bool operator>=(Fixed const &obj);
		bool operator<=(Fixed const &obj);
		bool operator==(Fixed const &obj);
		bool operator!=(Fixed const &obj);

		Fixed operator+(Fixed const &obj);
		Fixed operator-(Fixed const &obj);
		Fixed operator*(Fixed const &obj);
		Fixed operator/(Fixed const &obj);

		Fixed operator++(int);
		const Fixed &operator++();
		Fixed operator--(int);
		const Fixed &operator--();

		static Fixed &max(Fixed &v1, Fixed &v2);
		static Fixed &min(Fixed &v1, Fixed &v2);

		static const Fixed &max(Fixed const &v1, Fixed const &v2);
		static const Fixed &min(Fixed const &v1, Fixed const &v2);
};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif
