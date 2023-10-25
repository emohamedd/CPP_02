/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:51:31 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/25 10:46:28 by emohamed         ###   ########.fr       */
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
    Fpoint();
    Fpoint(Fpoint &point);
    Fpoint(const int point);
    Fpoint (const float point);
    ~Fpoint();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    void operator=(Fpoint const &point);
    void operator+(Fpoint const &point);
    void operator-(Fpoint const &point);
    void operator*(Fpoint const &point);
    void operator/(Fpoint const &point);
    bool operator>(Fpoint const &point);
    bool operator<(Fpoint const &point);
    bool operator>=(Fpoint const &point);
    bool operator<=(Fpoint const &point);
    bool operator==(Fpoint const &point);
    bool operator!=(Fpoint const &point);
    float toFloat(void) const;
    int toInt(void) const;
};
#endif