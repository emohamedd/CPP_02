/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/27 12:18:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fpoint::Fpoint(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

// Fpoint::Fpoint(Fpoint point)
// {
//     std::cout << "Copy constructor called" << std::endl;
//     this->fixed_point = point.getRawBits();
// }

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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fpoint::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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