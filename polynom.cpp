//
// Created by Omri Carmi on 23/01/2017.
//

#include "polynom.h"

polynom::polynom(int n, int *coefs) : n_(n){
    if(coefs == NULL){
        n_ = 0;
        coefs_ = NULL;
        return;
    }
    coefs_ = createCopyCoefs(n,coefs);
}

//TODO check if not cause mem leaks !!!!
polynom::polynom(const polynom &rhs):polynom{rhs.n_,rhs.coefs_}{}

polynom &polynom::operator=(const polynom &rhs) {
    if (this != &rhs) {
        //free old members
        delete[] coefs_;
        //allocate new members
        n_ = rhs.n_;
        coefs_ = createCopyCoefs(n_,rhs.coefs_);
    }
    return *this;
}

polynom::~polynom() {
    delete[] coefs_;
}

int *createCopyCoefs(int n,int *coefs) {
    int* coefsCopy = new int[n+1];
    for (int i = 0; i < n+1; ++i) {
        coefsCopy[i] = coefs[i];
    }
    return coefsCopy;
}

polynom polynom::operator+(const polynom &rhs) const {
    //get the bigger order
    int n = (n_>rhs.n_)?n_:rhs.n_;
    //create new coefs with size like the bigger one
    int* coefs = new int[n+1];
    //init all coefs to 0
    for (int i = 0; i < n+1; ++i) {
        coefs[i] = 0;
    }
    //add the lhs coefs
    for (int i = 0; i < n_+1; ++i) {
        coefs[i] += coefs_[i];
    }
    //add the rhs coefs
    for (int i = 0; i < rhs.n_+1; ++i) {
        coefs[i] += rhs.coefs_[i];
    }
    //return new polynom with the new calc coefs and order
    return polynom(n,coefs);
}

polynom polynom::operator-(const polynom &rhs) const {
    //get the bigger order
    int n = (n_>rhs.n_)?n_:rhs.n_;
    //create new coefs with size like the bigger one
    int* coefs = new int[n+1];
    //init all coefs to 0
    for (int i = 0; i < n+1; ++i) {
        coefs[i] = 0;
    }
    //add the lhs coefs
    for (int i = 0; i < n_+1; ++i) {
        coefs[i] += coefs_[i];
    }
    //sub the rhs coefs
    for (int i = 0; i < rhs.n_+1; ++i) {
        coefs[i] -= rhs.coefs_[i];
    }
    //return new polynom with the new calc coefs and order
    return polynom(n,coefs);
}

polynom polynom::operator*(const polynom &rhs) const {
    //calc the new order
    int n = n_ + rhs.n_;
    //create new coefs with size like the bigger one
    int* coefs = new int[n+1];
    //init all coefs to 0
    for (int i = 0; i < n+1; ++i) {
        coefs[i] = 0;
    }
    //TODO validate correctness with @Harel
    //iterate over the lhs coefs
    for (int i = 0; i < n_+1; ++i) {
        //add it multiple with all rhs coefs each one to its correct place
        for (int j = 0; j < rhs.n_ +1; ++j) {
            coefs[i+j] += coefs_[i]*rhs.coefs_[j];
        }
    }
    //return new polynom with the new calc coefs and order
    return polynom(n,coefs);
}

int polynom::GetOrder() const{
    return n_;
}

int *polynom::GetCoefs() const {
    return createCopyCoefs(n_,coefs_);
}

polynom operator*(const int &scalar, const polynom &poly){
    //create new coefs with same size
    int n = poly.n_;
    int* coefs = createCopyCoefs(n,poly.coefs_);
    //multiple all coefs by scalar
    for (int i = 0; i < n+1; ++i) {
        coefs[i] *= scalar;
    }
    //return new polynom with the new calc coefs and order
    return polynom(n,coefs);
}

ostream& operator<<(ostream &ro, const polynom& poly) {
    cout << poly.toString();
    return ro;
}



string polynom::toString() const {
    string str = "";
    bool isFirst = true;
    for (int i = n_ ; i >= 0; --i) {
        //skip 0 coefficients
        if(coefs_[i] == 0) continue;
        //add + sign if positive and not first coefficient
        if(coefs_[i] > 0 && !isFirst){
            str += "+";
        }
        if(isFirst){
            if(i==0){
                //if the first is a0 so it just him
                return to_string(coefs_[i]);

            }
            if(coefs_[i] == -1){
                str += "-";
            }else if(coefs_[i] != 1){
                str += to_string(coefs_[i]);
            }
            //add the x with right order
            str += "x";
            //add power if bigger than 1
            if(i>1) {
                str += "^" + to_string(i);
            }
            isFirst = false;
        }else{
            //set that already add first coefficient
            //add the coefficient if different from 1
            if(i != 0){
                if(coefs_[i] == -1){
                    str += "-";
                }else if(coefs_[i] != 1){
                    str += to_string(coefs_[i]);
                }
                //add the x with right order
                str += "x";
                //add power if bigger than 1
                if(i>1) {
                    str += "^" + to_string(i);
                }
            }else{
                str += to_string(coefs_[i]);
            }
        }
    }

    //if total zero print just 0
    if(isFirst) {
        str += "0";
    }
    //return the final string
    return str;
}

int InnerProduct(const polynom &x, const polynom &y) {
    polynom integrand = x*y;
    //integral on integrand 0 ---> 1
    //init to 0
    //sum with a0
    int sum = integrand.coefs_[0];
    //sum all the rest a(1--->n)
    for (int i = 1; i < integrand.n_ + 1; ++i) {
        int* coefs = integrand.coefs_;
        sum += ( coefs[i] / (i+1) ); //TODO maybe need cast for round number problem
    }

    return sum;
}

int SqNorm(const polynom &c) {
    return InnerProduct(c,c);
}

int SqDistance(const polynom &x, const polynom &y) {
    return SqNorm(x-y);
}



