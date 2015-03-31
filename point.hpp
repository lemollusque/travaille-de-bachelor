/* 
 * File:   point.hpp
 * Author: Bastian
 *
 * Created on 8. mars 2015, 15:51
 */

#ifndef POINT_HPP
#define	POINT_HPP
#include <iostream>
class point
{
private:
    int64_t m_x;
    int64_t m_y;
public:     
    int64_t get_x();                              //fonctions pour avoir acces a x et y
    int64_t get_y();
    /*constructeur*/
    point (int64_t x, int64_t y);
    point(point const& autre);                   //constructeur de copie
};

#endif	/* POINT_HPP */

