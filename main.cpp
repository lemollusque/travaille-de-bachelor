

/* 
 * File:   main.cpp
 * Author: Bastian
 *
 * Created on 27. février 2015, 23:07
 */

 
#include <gmp.h>
#include <cstdlib>
#include <iostream>
#include<string>
#include <chrono>
#include <thread>
#include "courbe_elliptique.hpp"
#include "point.hpp"
#include "multmodp.hpp"
#include <gmpxx.h>
#include <vector>
#include <ctime>




 

int main(int argc, char** argv) {
   
    
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

   vector< mpz_class> tab(1,2);                                                                                 //algorithme crible d'Eratosthène
    for(int i=3; i<100; ++i)
    {
        int remainder(1);
        for(int j=0; j<tab.size(); ++j)
        {
            
            if (i%tab[j]==0)
            {
                remainder=0;
            }
            
        }
        if (remainder==1)
        {
            tab.push_back(i);
        }
    }
    

   
   for(int i=0; i<tab.size(); ++i)
   {
       
       
        point P(1, 3);
        mpz_class  m = 7;
        courbe_elliptique courbe = courbe_elliptique(3, 5, tab[i]);
        if(courbe.sing()==1)
        {
               
                cout << courbe.trouver_m(P,courbe.mult(P,m))<<endl;
        }
       
   }
  
    end = std::chrono::high_resolution_clock::now();
 
    int elapsed_mseconds = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();
    std::time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);
    std::cout << (end-start).count() << endl;
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_mseconds << "ms\n";

    
    return 0;
}
