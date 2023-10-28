/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 18:21:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    this->fixed_point = 0;
}

Fixed::Fixed(Fixed const &point)
{
    Fixed::operator = (point);
}
void Fixed::operator=(Fixed const &point)
{
    this->fixed_point = point.getRawBits();
}
Fixed::Fixed(const int point)
{
    int conv = point * (1 << this->bits);
    this->fixed_point  = conv;
}
Fixed::Fixed(const float point)
{
    int conv = roundf(point * (1 << this->bits));
    this->fixed_point  = conv;
}
 Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
 const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
 Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed::~Fixed(){
}
int Fixed::getRawBits() const{
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}
int Fixed::toInt(void) const
{
    // int pow = std::pow(2, this->bits);
    int res = this->fixed_point  / (1 << this->bits);
    return (res);
}
float Fixed::toFloat(void) const{
    //  int pow = std::pow(2, this->bits);
    float res = float(this->fixed_point) / (1 << this->bits);
     return (res);
}

Fixed Fixed::operator+(Fixed const &point)
{
    this->fixed_point = this->fixed_point + point.getRawBits();
    return (this->fixed_point);
}
Fixed Fixed::operator-(Fixed const &point)
{
    this->fixed_point = this->fixed_point - point.getRawBits();
    return (this->fixed_point);
}
Fixed Fixed::operator*(Fixed const &point)
{
    // Fixed no = (*this);
    
    this->fixed_point = (this->fixed_point * point.fixed_point) / (1 << this->bits);
    return (*this);
}   
Fixed Fixed::operator/(Fixed const &point)
{
    this->fixed_point = (this->fixed_point / point.getRawBits()) * (1 << this->bits);
    return (*this);
}
bool Fixed::operator>(Fixed const &point)
{
    return (this->fixed_point > point.getRawBits());
}
bool Fixed::operator<(Fixed const &point)
{
    return (this->fixed_point < point.getRawBits());
}
bool Fixed::operator>=(Fixed const &point)
{
    return !(this->fixed_point < point.getRawBits());
}
bool Fixed::operator<=(Fixed const &point)
{
    return !(this->fixed_point > point.getRawBits());
}
bool Fixed::operator==(Fixed const &point)
{
    return (this->fixed_point == point.getRawBits());
}
bool Fixed::operator!=(Fixed const &point)
{
    return (this->fixed_point != point.getRawBits());
}
Fixed& Fixed::operator++()
{
    this->fixed_point++;
    return (*this);
}
Fixed& Fixed::operator--()
{
    this->fixed_point--;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    operator++();
    return (tmp);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    operator--();
    return (tmp);
}
std::ostream& operator<<(std::ostream& os, const Fixed& point)
{
    os << point.toFloat();
    return (os);
}
