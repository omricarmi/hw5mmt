//
// Created by Omri Carmi on 22/01/2017.
//

#include <iostream>
#include <cassert>
#include "complex.h"

void testComplex();

using namespace std;

int main(){
    cout << "TESTS:" << endl;

    testComplex();

}

void testComplex() {

    cout << complex(2,0) << endl; // prints 2
    cout << complex(-2,0)<< endl ; // prints -2
    cout << complex(0,0)<< endl ; // prints 0
    cout << complex(2,1)<< endl ; // prints 2+i
    cout << complex(2,-1)<< endl ; // prints 2-i
    cout << complex(0,1)<< endl ; // prints i
    cout << complex(0,-1)<< endl ; // prints -i

}