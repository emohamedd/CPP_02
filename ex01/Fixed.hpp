/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:51:31 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/28 17:29:13 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed{
private:
    int fixed_point;
    static const int bits = 8;
public:
    Fixed();
    Fixed(Fixed const &point);
    Fixed  (const int point);
    Fixed  (const float point);
    ~Fixed();
    int getRawBits(void) const;
    int get_fixed_point(void) const;
    void setRawBits(int const raw);
    void operator=(Fixed const &point);
    float toFloat(void) const;
    int toInt(void) const;
};
    std::ostream& operator<<(std::ostream& os, const Fixed& point);
#endif