/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 17:28:16 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fpoint::Fpoint(){
    this->fixed_point = 0;
}

Fpoint::Fpoint(Fpoint const &point)
{
    Fpoint::operator = (point);
}
void Fpoint::operator=(Fpoint const &point)
{
    this->fixed_point = point.getRawBits();
}
Fpoint::Fpoint(const int point)
{
    int conv = point * (1 << this->bits);
    this->fixed_point  = conv;
}
Fpoint::Fpoint(const float point)
{
    int conv = roundf(point * (1 << this->bits));
    this->fixed_point  = conv;
}
 Fpoint& Fpoint::min(Fpoint &a, Fpoint &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
 const Fpoint& Fpoint::min(const Fpoint &a, const Fpoint &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
 Fpoint& Fpoint::max(Fpoint &a, Fpoint &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
const Fpoint& Fpoint::max(const Fpoint &a, const Fpoint &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fpoint::~Fpoint(){
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
    this->fixed_point = this->fixed_point + point.getRawBits();
    return (this->fixed_point);
}
Fpoint Fpoint::operator-(Fpoint const &point)
{
    this->fixed_point = this->fixed_point - point.getRawBits();
    return (this->fixed_point);
}
Fpoint Fpoint::operator*(Fpoint const &point)
{
    // Fpoint no = (*this);
    
    this->fixed_point = (this->fixed_point * point.fixed_point) / (1 << this->bits);
    return (*this);
}   
Fpoint Fpoint::operator/(Fpoint const &point)
{
    this->fixed_point = (this->fixed_point / point.getRawBits()) * (1 << this->bits);
    return (*this);
}
bool Fpoint::operator>(Fpoint const &point)
{
    return (this->fixed_point > point.getRawBits());
}
bool Fpoint::operator<(Fpoint const &point)
{
    return (this->fixed_point < point.getRawBits());
}
bool Fpoint::operator>=(Fpoint const &point)
{
    return !(this->fixed_point < point.getRawBits());
}
bool Fpoint::operator<=(Fpoint const &point)
{
    return !(this->fixed_point > point.getRawBits());
}
bool Fpoint::operator==(Fpoint const &point)
{
    return (this->fixed_point == point.getRawBits());
}
bool Fpoint::operator!=(Fpoint const &point)
{
    return (this->fixed_point != point.getRawBits());
}
Fpoint& Fpoint::operator++()
{
    this->fixed_point++;
    return (*this);
}
Fpoint& Fpoint::operator--()
{
    this->fixed_point--;
    return (*this);
}
Fpoint Fpoint::operator++(int)
{
    Fpoint tmp = *this;
    operator++();
    return (tmp);
}
Fpoint Fpoint::operator--(int)
{
    Fpoint tmp = *this;
    operator--();
    return (tmp);
}
std::ostream& operator<<(std::ostream& os, const Fpoint& point)
{
    os << point.toFloat();
    return (os);
}
