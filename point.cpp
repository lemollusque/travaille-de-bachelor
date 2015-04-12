#include "point.hpp"
#include <gmpxx.h>
#include <gmp.h>

mpz_class point::get_x()               //fonctions pour avoir acces a x et y
{
    return m_x;
}
mpz_class point::get_y()
{
    return m_y;
}




/*******constructeurs**************/
point::point(mpz_class x, mpz_class y)
{
    m_x=x;
    m_y=y;
    
}
point::point(point const& autre)        //constructeur de copie
: m_x(autre.m_x), m_y(autre.m_y)
{
    
}
