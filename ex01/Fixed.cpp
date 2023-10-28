/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 17:29:13 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(Fixed const &point)
{
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator = (point);
}
void Fixed::operator=(Fixed const &point)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point = point.getRawBits();
}
Fixed::Fixed(const int point)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = point * (1 << this->bits);
    // this->fixed_point  = conv;
}
int Fixed::get_fixed_point(void) const
{
    return (this->fixed_point);
}
Fixed::Fixed(const float point)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(point * (1 << this->bits));
} 
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits() const{
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}
std::ostream& operator<<(std::ostream& os, const Fixed& point)
{
    os << point.toFloat();
    return (os);
}
int Fixed::toInt(void) const
{
    int pow = std::pow(2, this->bits);
    int res = this->fixed_point  / pow;
    return (res);
}
float Fixed::toFloat(void) const{
     int pow = std::pow(2, this->bits);
    float res = float(this->fixed_point) / pow;
     return (res);
}
