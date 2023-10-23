/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/23 13:24:44 by emohamed         ###   ########.fr       */
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