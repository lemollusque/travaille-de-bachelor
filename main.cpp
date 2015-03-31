


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


 

int main(int argc, char** argv) {
    
    


    int k = 20;
    int p = 8; //un nombre de mèrsenne +1
    point P(1, 3);
    
    for (int i = 1; i < 22; ++i) {
        int m;
        m = 5;
        courbe_elliptique courbe = courbe_elliptique(3, 5, p - 1);
        
        int isprime = 1;
        for(int j=0;j<k;j++)
        {
            int a = (rand()%(p-2))+1;
            if(courbe.MillerRabin(a)==0)
            {
                cout << p - 1 << "   forcement pas premier" << endl;
                isprime=0;
                break;
            }
        }
       
        if (isprime) {
            cout << p - 1 << " probablement premier et m =" <<courbe.trouver_m(P,courbe.mult(P,m))<<endl;
            //actualise le nombre de mersenne
        }
        p = p * 2;
    }

 
    return 0;
}

