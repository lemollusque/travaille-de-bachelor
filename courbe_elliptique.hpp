/* 
 * File:   courbe_elliptique.hpp
 * Author: Bastian
 *
 * Created on 27. février 2015, 22:36
 */

#ifndef COURBE_ELLIPTIQUE_HPP
#define	COURBE_ELLIPTIQUE_HPP
#include <vector>
#include <exception>
#include <iostream>
#include "point.hpp"
#include <cstdint>
using namespace std;



class courbe_elliptique 
{
private:
    int64_t m_a,m_b;
    int64_t  m_p;                    //m_a le coeff devant x et m_b la constante, m_p le nombre premier du corps Fp
public:
    bool MillerRabin(int64_t k);     //vérfie si m_p est premier
    bool sing();                        //vérifie si la courbe est singuliere ou non
    int64_t eval(int64_t x);                    //pour àvaluer le polynôme en x pour ensuite l'utiliser dans is_contained
    bool is_contained(point p);         //vérifie si un point est sur la courbe
    int64_t findInverse(int64_t a);             //trouve un inverse de a dans Z/pZ

    point addition(point p1, point p2); //addition de deux point
    point mult_2(point p);              //multiplication par 2
    point mult(point p, int64_t m);         //multiplication par m
    int64_t trouver_m(point p,point mp);    //fonction pour retrouver la multiplication m
    //constructeur
    courbe_elliptique (int64_t a, int64_t b, int64_t p);
  
    
};

#endif	/* COURBE_ELLIPTIQUE_HPP */

