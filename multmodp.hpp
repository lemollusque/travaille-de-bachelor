/* 
 * File:   multmodp.hpp
 * Author: bastian
 *
 * Created on 1. avril 2015, 15:36
 */
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include "courbe_elliptique.hpp"
#include "point.hpp"
#include <gmpxx.h>

#ifndef MULTMODP_HPP
#define	MULTMODP_HPP

class multmodp
{
public:
    int64_t mult5(int64_t a, int64_t b, int64_t p);
};



#endif	/* MULTMODP_HPP */

