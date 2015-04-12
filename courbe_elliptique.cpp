#include "courbe_elliptique.hpp"
#include "point.hpp"
#include <cmath>
#include <cstdint>
#include "multmodp.hpp"
#include <gmpxx.h>
#include <gmp.h>
//element neutre (p+1, p+1)

mpz_class courbe_elliptique::mmp(mpz_class a, mpz_class b) //fonction qui multiplie en modulant apres chaque étape
{
    a=a%m_p;
    b=b%m_p;
    if(a<0)
    {
        a=a+m_p;
    }
    if(b<0)
    {
        b=b+m_p;
    }
    mpz_class resultat=0;
    
    if(a%m_p==0 or b%m_p==0)
    {
        return  resultat;
    }
   
    
    for(int i=1; i<=b; ++i)
    {
        resultat=(resultat+a)%m_p;
    }
    return resultat;
}
/****************************************************************************************************/

bool courbe_elliptique::sing()                      //vérifie si la courbe est singuliere ou non
{   
    
    return 4*mmp(mmp(m_a,m_a),m_a)+mmp(mmp(27,m_b),m_b)!=0;             //singuliere si return 0
}

mpz_class courbe_elliptique::eval(mpz_class x)                  //pour àvaluer le polynôme en x pour ensuite l'utiliser dans is_contained
{
    return mmp(mmp(x,x),x)+mmp(x,m_a)+m_b;
}
bool courbe_elliptique::is_contained(point p)       //vérifie si un point est sur la courbe
{   
    if(p.get_x()==m_p+1 and p.get_y()==m_p+1)
    {
        return 1;
    }
    mpz_class a,b;                                        //on va comparer a=y^2 et b=f(x)
    a=(p.get_y()*p.get_y())%m_p;
    b=eval(p.get_x())%m_p;
    if(a<=0)                                        //met a et b entre 0 et le nombre premier
        {
            a=a+m_p;
        }   
    if(b<=0)                                           
        {
            b=b+m_p;
        }   
    
    return a==b;
}


mpz_class courbe_elliptique::findInverse(mpz_class z)           //http://www.pagedon.com/extended-euclidean-algorithm-in-c/my_programming/
                                                    //trouver un inverse de a dans Z/pZ
{
    mpz_class a=z;
    if(a<0)
    {
        a=a+m_p;
    }
mpz_class p=m_p;
mpz_class x[3];
mpz_class y[3];
mpz_class quotient  = a / p;
mpz_class remainder = a % p;

x[0] = 0;
y[0] = 1;
x[1] = 1;
y[1] = quotient * -1;

int i = 2;
for (; (p % (a%p)) != 0; i++)
{
a = p;
p = remainder;
quotient = a / p;
remainder = a % p;
x[i % 3] = (quotient * -1 * x[(i - 1) % 3]) + x[(i - 2) % 3];
y[i % 3] = (quotient * -1 * y[(i - 1) % 3]) + y[(i - 2) % 3];
}

//x[i - 1 % 3] is inverse of a

return x[(i - 1) % 3];
}

/************************************operations sur les points*****************************************/

point  courbe_elliptique::addition(point p1, point p2)  //addition de deux point
{   
    if(p1.get_x()==p2.get_x() and p1.get_y()==p2.get_y())
    {
        return mult_2(p1);
    }
    if(p1.get_x()==m_p+1 and p1.get_y()==m_p+1)         //traie les cas ou un des deux point est lelem. neutre
    {
        return p2;
    }
    if(p2.get_x()==m_p+1 and p2.get_y()==m_p+1)
    {
        return p1;
    }
      
    mpz_class lambda,nu,x3,y3;
    try

    {   
        //if(sing()==0)                                                           //test si la courbe est singuliere
          //  throw string("courbe singuliere !");
        if(is_contained(p1)==0 or is_contained(p2)==0)                          //verifie si le point est sur la courbe
            throw string("un des points n'est pas sur la courbe");
        if(0 == (p2.get_x()-p1.get_x())%m_p)                                    //verifie si il y a une division par 0 modulo p dans le calcul
            {
            point P(m_p+1, m_p+1);
            return P;
        };
        
    lambda=mmp(p2.get_y()-p1.get_y(),findInverse(p2.get_x()-p1.get_x()));
    nu=(p1.get_y()-mmp(lambda,p1.get_x()))%m_p;
    x3=(mmp(lambda,lambda)-p1.get_x()-p2.get_x())%m_p;
    y3=(-mmp(lambda,x3)-nu)%m_p;
    if(x3<0)
    {
        x3=x3+m_p;
    }
    if(y3<0)
    {
        y3=y3+m_p;
    }
    point add(x3,y3);                                                
    return add;
     }

   catch(string const& chaine)

   {

       cerr << chaine << endl;

   }

}

point courbe_elliptique::mult_2(point p)   // multiplie un point par m
{
    
    mpz_class lambda,nu,new_x,new_y;
    
    try

    {   
        if(sing()==0)                                                       //test si la courbe est singuliere
            throw string("courbe singuliere !");
        if(is_contained(p)==0)                                              //verifie si le point est sur la courbe
            throw string("le point n'est pas sur la courbe");
        if(0 == (2*p.get_y())%m_p)                                          //verifie si il y a une division par 0 modulo p dans le calcul
        {
            point P(m_p+1, m_p+1);
            return P;
        };
                                                                            //calcul le nouveau point
        
        lambda=mmp(p.get_x(), p.get_x());
        lambda=(((lambda+lambda)%m_p+lambda)%m_p+m_a)%m_p;
        lambda=mmp(lambda, findInverse((2*p.get_y())%m_p));
        nu=p.get_y()-mmp(lambda, p.get_x());
        new_x=(mmp(lambda, lambda)-p.get_x()-p.get_x())%m_p;
        new_y=(-mmp(lambda, new_x)-nu)%m_p;
        if(new_x<0)                                                        //met x et y entre 0 et le nombre premier
        {
            new_x=new_x+m_p;
        }
        
         if(new_y<0)
        {
            new_y=new_y+m_p;
        }
        point P(new_x, new_y);                                    
        return P;
    }

   catch(string const& chaine)

   {

       cerr << chaine << endl;

   }

}
    
    
point courbe_elliptique::mult(point p, mpz_class m)               // multiplie un point par m
{   
    point q(m_p+1, m_p+1);                                  //initialise à elem neutre
    
    mpz_class remainder=m;
    while(remainder>0)
    {
        
        point remainderpoint(p);   
   
        mpz_class k=1;
        while(2*k<=remainder)
        {
           remainderpoint=mult_2(remainderpoint);
           k=2*k;
        }
        q=addition(q,remainderpoint);
        remainder=remainder-k;
        
        
    
    }
    return q;
}

mpz_class courbe_elliptique::trouver_m(point p,point mp)          //fonction pour retrouver la multiplication m
{
    mpz_class k=1;
    point remainder(p);
    while(remainder.get_x()!=mp.get_x() or remainder.get_y()!=mp.get_y())
    {
        k=k+1;
        remainder=addition(p,remainder);
    }
    return k;
}


/****************************constructeur****************************************/
courbe_elliptique::courbe_elliptique(mpz_class a, mpz_class b, mpz_class p)
{
    m_a=a;
    m_b=b;
    m_p=p;
    
}