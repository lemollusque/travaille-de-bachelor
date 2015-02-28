/* 
 * File:   courbe_elliptique.hpp
 * Author: Bastian
 *
 * Created on 27. février 2015, 22:36
 */

#ifndef COURBE_ELLIPTIQUE_HPP
#define	COURBE_ELLIPTIQUE_HPP

class courbe_elliptique 
{
private:
    int m_a,m_b,m_c,m_d;
public:
    int eval(int x);
    bool is_contained(int x, int y);
    
    int get_a();
    
    //constructeur
    courbe_elliptique (int a, int b, int c, int d);
  
    
};

#endif	/* COURBE_ELLIPTIQUE_HPP */

