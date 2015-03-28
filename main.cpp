/* 
 * File:   main.cpp
 * Author: Bastian
 *
 * Created on 27. février 2015, 23:07
 */


#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include "courbe_elliptique.hpp"
#include "point.hpp"


/*
 * 
 */
int main(int argc, char** argv) {
    
    
 
    int p=8;                                    //un nombre de marsenne +1
    point P(1, 3);
    for(int i=1; i<22; ++i)
    {
        int m;
        m=5;
        courbe_elliptique courbe=courbe_elliptique(3,5, p-1);
        if(courbe.MillerRabin(5)==1)
        {
        
        
        cout<<p-1<<" est premier ="<<endl;//courbe.trouver_m(P,courbe.mult(P,m))<<endl;
                                          //actualise le nombre de mersenne
        }
        if(courbe.MillerRabin(5)==0)
        {   
            cout<<p-1<<"   nest probablement pas premier"<<endl;
            
        
        }
        p=p*2;
    }
    
    return 0;
}

