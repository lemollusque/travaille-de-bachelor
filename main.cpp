/* 
 * File:   main.cpp
 * Author: Bastian
 *
 * Created on 27. février 2015, 23:07
 */
#include <iostream>
#include <cstdlib>
#include "courbe_elliptique.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    courbe_elliptique nimp=courbe_elliptique(1, 2, 3, 4);
    cout << "Hello World!" << endl;
    cout << nimp.get_a()<< endl;
    return 0;
}

