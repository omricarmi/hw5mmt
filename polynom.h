#ifndef _POLY_F
#define _POLY_F
#include <iostream>

using namespace std;


class polynom  {

protected:
    int n_;
    int* coefs_;
public:
    polynom(int n=0, int* coefs=NULL);

    polynom(const polynom& rhs);
    virtual ~polynom();
    polynom& operator=(const polynom &rhs);

    //Operators
    polynom operator+(const polynom &rhs) const;
    polynom operator-(const polynom &rhs) const;
    polynom operator*(const polynom &rhs) const;
    friend polynom operator*(const int &scalar,const polynom &poly);
    friend ostream& operator<<(ostream& ro,const polynom& poly);

    friend int InnerProduct(const polynom& x,const polynom& y);
    friend int SqNorm(const polynom& c);
    friend int SqDistance(const polynom& x,const polynom& y);

    int GetOrder() const;
    int* GetCoefs() const;
    string toString() const;
};

polynom operator*(const int &scalar,const polynom &poly);
ostream& operator<<(ostream& ro,const polynom& poly);
int InnerProduct(const polynom& x,const polynom& y);
int SqNorm(const polynom& c);
int SqDistance(const polynom& x,const polynom& y);
int* createCopyCoefs(int n, int* coefs);

#endif
 
