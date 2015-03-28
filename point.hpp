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
    int m_x;
    int m_y;
public:     
    int get_x();                              //fonctions pour avoir acces a x et y
    int get_y();
    /*constructeur*/
    point (int x, int y);
    point(point const& autre);                   //constructeur de copie
};

#endif	/* POINT_HPP */

