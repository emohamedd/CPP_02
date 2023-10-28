/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:51:31 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 17:29:13 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed{       
private:
    int fixed_point;
    static const int bits = 8;
public:
    //constructors
    Fixed();
    Fixed(Fixed const &point);
    Fixed  (const int point);
    Fixed  (const float point);
    ~Fixed();
    //methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    //static methods
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed & max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    //assignment operators
    void operator=(Fixed const &point);
    //arithmetic operators
    Fixed operator+(Fixed const &point);
    Fixed operator-(Fixed const &point);
    Fixed operator*(Fixed const &point);
    Fixed operator/(Fixed const &point);
    //comparison operators
    bool operator>(Fixed const &point);
    bool operator<(Fixed const &point);
    bool operator>=(Fixed const &point);
    bool operator<=(Fixed const &point);
    bool operator==(Fixed const &point);
    bool operator!=(Fixed const &point);
    //increment operators
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    
};
    //stream operators
    std::ostream& operator<<(std::ostream& os, const Fixed& point);
#endif