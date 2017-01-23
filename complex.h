#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

using namespace std;

class complex  {

protected:
  int re_;
  int im_;

public:
    //Constructors
    complex(int real=0,int img=0);

    //Operators - Arithmetic
    complex operator+(const complex& rhs) const;
//    complex& operator+=(const complex& rhs);
    complex operator-(const complex& rhs)const;
//    complex& operator-=(const complex& rhs);
    complex operator*(const complex& rhs)const;
//    complex& operator*=(const complex& rhs);


    //Operators - IO Stream
    friend ostream& operator<<(ostream& ro,const complex c);

    //Math Helpers
    friend complex conj(const complex& c);
    friend complex InnerProduct(const complex& x,const complex& y);
    friend complex SqNorm(const complex& c);
    friend complex SqDistance(const complex& x,const complex& y);

private:
    void print(ostream& ro) const;
    void printImg(ostream& ro) const;
};

complex conj(const complex& c);
complex InnerProduct(const complex& x,const complex& y);
complex SqNorm(const complex& c);
complex SqDistance(const complex& x,const complex& y);

//ostream &operator<<(ostream &ro, const complex c) const;

#endif
