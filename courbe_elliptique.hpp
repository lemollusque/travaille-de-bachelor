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

using namespace std;



class courbe_elliptique 
{
private:
    int m_a,m_b,m_p;                    //m_a le coeff devant x et m_b la constante, m_p le nombre premier du corps Fp
public:
    bool MillerRabin(int k);     //vérfie si m_p est premier
    bool sing();                        //vérifie si la courbe est singuliere ou non
    int eval(int x);                    //pour àvaluer le polynôme en x pour ensuite l'utiliser dans is_contained
    bool is_contained(point p);         //vérifie si un point est sur la courbe
    int findInverse(int a);             //trouve un inverse de a dans Z/pZ

    point addition(point p1, point p2); //addition de deux point
    point mult_2(point p);              //multiplication par 2
    point mult(point p, int m);         //multiplication par m
    int trouver_m(point p,point mp);    //fonction pour retrouver la multiplication m
    //constructeur
    courbe_elliptique (int a, int b, int p);
  
    
};

#endif	/* COURBE_ELLIPTIQUE_HPP */

