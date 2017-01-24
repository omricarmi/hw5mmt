//
// Created by Omri Carmi on 22/01/2017.
//

#include <iostream>
#include <cassert>
#include "complex.h"
#include "polynom.h"

void testComplex();

void testPolynom();

using namespace std;

int main(){
    cout << "TESTS:" << endl;

    testComplex();

    testPolynom();
}

void testPolynom() {

    polynom p(2,(int[]){1,0,2});
    assert( "2x^2+1" == p.toString());
    p = polynom(3,(int[]){1,0,2,9});
    assert( "9x^3+2x^2+1" == p.toString());

}

void testComplex() {

    assert( "2" == complex(2,0).toString());
    assert( "-2" == complex(-2,0).toString());
    assert( "0" == complex(0,0).toString());
    assert( "2+i" == complex(2,1).toString());
    assert( "2-i" == complex(2,-1).toString());
    assert( "i" == complex(0,1).toString());
    assert( "-i" == complex(0,-1).toString());

}