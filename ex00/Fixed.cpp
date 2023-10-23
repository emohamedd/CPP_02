/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:17 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/23 11:18:06 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fpoint::Fpoint(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fpoint::Fpoint(Fpoint &point)
{
    this->fixed_point = point.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
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