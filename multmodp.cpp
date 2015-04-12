#include "multmodp.hpp"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include "courbe_elliptique.hpp"
#include "point.hpp"
#include <gmpxx.h>

int64_t mult5(int64_t a, int64_t b, int64_t p)
{
    a=a%p;
    b=b%p;
    if(a<0)
    {
        a=a+p;
    }
    if(b<0)
    {
        b=b+p;
    }
    int64_t resultat=0;
    
    if(a%p==0 or b%p==0)
    {
        return  resultat;
    }
   
    
    for(int i=1; i<b; ++i)
    {
        resultat=(resultat+a)%p;
    }
    return resultat;
}




