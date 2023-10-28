/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:51:31 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 12:50:27 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fpoint{
private:
    int fixed_point;
    static const int bits = 8;
public:
    //constructors
    Fpoint();
    Fpoint(Fpoint const &point);
    Fpoint  (const int point);
    Fpoint  (const float point);
    ~Fpoint();
    //methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    //static methods
    static Fpoint& min(Fpoint &a, Fpoint &b);
    static const Fpoint& min(const Fpoint &a, const Fpoint &b);
    static Fpoint& max(Fpoint &a, Fpoint &b);
    static const Fpoint& max(const Fpoint &a, const Fpoint &b);
    //assignment operators
    void operator=(Fpoint const &point);
    //arithmetic operators
    Fpoint operator+(Fpoint const &point);
    Fpoint operator-(Fpoint const &point);
    Fpoint operator*(Fpoint const &point);
    Fpoint operator/(Fpoint const &point);
    //comparison operators
    bool operator>(Fpoint const &point);
    bool operator<(Fpoint const &point);
    bool operator>=(Fpoint const &point);
    bool operator<=(Fpoint const &point);
    bool operator==(Fpoint const &point);
    bool operator!=(Fpoint const &point);
    
};
    std::ostream& operator<<(std::ostream& os, const Fpoint& point);
#endif