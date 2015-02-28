#include "courbe_elliptique.hpp"

int courbe_elliptique::eval(int x) 
{
    return x*x*x*m_a+x*x*m_b+x*m_c+m_d;
}
bool courbe_elliptique::is_contained(int x, int y)
{
    return y*y==eval(x);
}
int courbe_elliptique::get_a()
{
    return m_a;
}
//constructeur
courbe_elliptique::courbe_elliptique(int a, int b, int c, int d)
{
    m_a=a;
    m_b=b;
    m_c=c;
    m_d=d;
}
