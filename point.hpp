/* 
 * File:   point.hpp
 * Author: Bastian
 *
 * Created on 8. mars 2015, 15:51
 */

#ifndef POINT_HPP
#define	POINT_HPP
#include <iostream>
#include <gmpxx.h>
#include <gmp.h>
class point
{
private:
    mpz_class m_x;
    mpz_class m_y;
public:     
    mpz_class get_x();                              //fonctions pour avoir acces a x et y
    mpz_class get_y();
    /*constructeur*/
    point (mpz_class x, mpz_class y);
    point(point const& autre);                   //constructeur de copie
};

#endif	/* POINT_HPP */

