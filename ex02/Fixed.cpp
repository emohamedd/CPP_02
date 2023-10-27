/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/25 11:23:29 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fpoint::Fpoint(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fpoint::Fpoint(Fpoint &point)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = point.getRawBits();
}
Fpoint::~Fpoint(){
    std::cout << "Destructor called" << std::endl;
}
int Fpoint::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fpoint::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}

void Fpoint::operator=(Fpoint const &point)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point = point.getRawBits();
    // return (this->fixed_point);
}
void Fpoint::operator+(Fpoint const &point)
{
    std::cout << "Addition operator called" << std::endl;
    this->fixed_point = this->fixed_point + point.getRawBits();
    // return (this->fixed_point);
}
void Fpoint::operator-(Fpoint const &point)
{
    std::cout << "Subtraction operator called" << std::endl;
    this->fixed_point = this->fixed_point - point.getRawBits();
    // return (this->fixed_point);
}
void Fpoint::operator*(Fpoint const &point)
{
    std::cout << "Multiplication operator called" << std::endl;
    this->fixed_point = this->fixed_point * point.getRawBits();
    // return (this->fixed_point);
}   
void Fpoint::operator/(Fpoint const &point)
{
    std::cout << "Division operator called" << std::endl;
    this->fixed_point = this->fixed_point / point.getRawBits();
    // return (this->fixed_point);
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
    return (this->fixed_point >= point.getRawBits());
}
bool Fpoint::operator<=(Fpoint const &point)
{
    std::cout << "Less than or equal to operator called" << std::endl;
    return (this->fixed_point <= point.getRawBits());
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
int Fpoint::toInt(void) const
{
    return (this->fixed_point >> this->bits);
}
 Fpoint::Fpoint(const int point)
{
    this->fixed_point = point;
}