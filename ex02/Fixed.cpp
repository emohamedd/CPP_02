/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 12:52:48 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fpoint::Fpoint(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fpoint::Fpoint(Fpoint const &point)
{
    std::cout << "Copy constructor called" << std::endl;
    Fpoint::operator = (point);
}
void Fpoint::operator=(Fpoint const &point)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point = point.getRawBits();
}
Fpoint::Fpoint(const int point)
{
    std::cout << "Int constructor called" << std::endl;
    int conv = point * (1 << this->bits);
    this->fixed_point  = conv;
}
Fpoint::Fpoint(const float point)
{
    std::cout << "Float constructor called" << std::endl;
    int conv = roundf(point * (1 << this->bits));
    this->fixed_point  = conv;
} 
Fpoint::~Fpoint(){
    std::cout << "Destructor called" << std::endl;
}
int Fpoint::getRawBits() const{
    return (this->fixed_point);
}

void Fpoint::setRawBits(int const raw)
{
    this->fixed_point = raw;
}
int Fpoint::toInt(void) const
{
    int pow = std::pow(2, this->bits);
    int res = this->fixed_point  / pow;
    return (res);
}
float Fpoint::toFloat(void) const{
     int pow = std::pow(2, this->bits);
    float res = float(this->fixed_point) / pow;
     return (res);
}

Fpoint Fpoint::operator+(Fpoint const &point)
{
    std::cout << "Addition operator called" << std::endl;
    this->fixed_point = this->fixed_point + point.getRawBits();
    return (this->fixed_point);
}
Fpoint Fpoint::operator-(Fpoint const &point)
{
    std::cout << "Subtraction operator called" << std::endl;
    this->fixed_point = this->fixed_point - point.getRawBits();
    return (this->fixed_point);
}
Fpoint Fpoint::operator*(Fpoint const &point)
{
    std::cout << "Multiplication operator called" << std::endl;
    this->fixed_point = this->fixed_point * point.getRawBits();
    return (this->fixed_point);
}   
Fpoint Fpoint::operator/(Fpoint const &point)
{
    std::cout << "Division operator called" << std::endl;
    this->fixed_point = this->fixed_point / point.getRawBits();
    return (this->fixed_point);
}
bool Fpoint::operator>(Fpoint const &point)
{
    std::cout << "Greater than operator called" << std::endl;
    return (this->fixed_point > point.getRawBits());
}
bool Fpoint::operator<(Fpoint const &point)
{
    std::cout << "Less than operator called" << std::endl;
    return (this->fixed_point < point.getRawBits());
}
bool Fpoint::operator>=(Fpoint const &point)
{
    std::cout << "Greater than or equal to operator called" << std::endl;
    return !(this->fixed_point < point.getRawBits());
}
bool Fpoint::operator<=(Fpoint const &point)
{
    std::cout << "Less than or equal to operator called" << std::endl;
    return !(this->fixed_point > point.getRawBits());
}
bool Fpoint::operator==(Fpoint const &point)
{
    std::cout << "Equal to operator called" << std::endl;
    return (this->fixed_point == point.getRawBits());
}
bool Fpoint::operator!=(Fpoint const &point)
{
    std::cout << "Not equal to operator called" << std::endl;
    return (this->fixed_point != point.getRawBits());
}
std::ostream& operator<<(std::ostream& os, const Fpoint& point)
{
    os << point.toFloat();
    return (os);
}
