#ifndef _TEMPVEC_H
#define _TEMPVEC_H

#include "complex.h"
#include <iostream>

using namespace std;
/*TODO - general questions:
 * 2. when is it necessary to define input variable and also the func itself as constant
*/
template <class T,int size>
class TempVec {
public:
    TempVec(){}
    TempVec<T,size>& operator=(TempVec& other);
    TempVec(const TempVec<T,size>& src);
    ~TempVec(){}//TODO - is there a need to delete something, ar define as virtual
    TempVec<T,size> operator+(const TempVec<T,size>& second) const;
    TempVec<T,size> operator-(const TempVec<T,size>& second) const;
    T& operator[](int index); // TODO - why cannot be const?
    template <class U,int size_>
    friend TempVec<U,size_> operator*(U scalar, const TempVec<U,size_>& second);

    template <class U,int size_>
    friend ostream & operator<<( ostream &output, const TempVec<U,size_>& Vec );

    //void print(int index) const{
    //}
    template <class U,int size_>
    friend U InnerProduct(const TempVec<U,size_>& first,const TempVec<U,size_>& second);
    template <class U,int size_>
    friend U SqNorm(const TempVec<U,size_>& vec);
    template <class U,int size_>
    friend U SqDistance(const TempVec<U,size_>& first,const TempVec<U,size_>& second);



protected:
    T coordinates_[size];
};
// copy constructor
template <class T,int size>
TempVec<T, size>::TempVec(const TempVec<T,size>& src){
    for (int i = 0; i < size; ++i) {
        coordinates_[i] = src.coordinates_[i];
    }
}
template <class T,int size>
TempVec<T,size>& TempVec<T,size>::operator=(TempVec<T,size>& other){
    if(this != &other) {
        //delete[] coordinates_; //TODO - is it needed to delete first (compare to lecture pg 94)
        for (int i = 0; i < size; ++i) {
            coordinates_[i] = other.coordinates_[i];
        }
    }
    return (*this);
}
template <class T,int size>
TempVec<T,size> TempVec<T,size>::operator+(const TempVec<T,size>& second) const{
    TempVec<T,size> sum;
    for (int i = 0; i < size ; ++i) {
        sum.coordinates_[i] = coordinates_[i] + second.coordinates_[i];
    }
    return sum;
};

template <class T,int size>
TempVec<T,size> TempVec<T,size>::operator-(const TempVec<T,size>& second) const{
    TempVec<T,size> sub;
    for (int i = 0; i < size ; ++i) {
        sub.coordinates_[i] = coordinates_[i] - second.coordinates_[i];
    }
    return sub;
};

template <class T,int size>
TempVec<T,size> operator*(T scalar ,const TempVec<T,size>& second){
    TempVec<T,size> multiplyed;
    for (int i = 0; i < size ; ++i) {
        multiplyed.coordinates_[i] = scalar*second.coordinates_[i];
    }
    return multiplyed;
};

template <class T,int size>
T& TempVec<T,size>::operator[](int index){
    if (index >= size || index < 0){
        throw ("Error TempVec. Illegal index");
    }
    return coordinates_[index]; //TODO - what would happen if we returned without *?
};

template <class T,int size>
ostream & operator<<(ostream &output, const TempVec<T,size>& Vec ) {
    output << "(";// << " I : " << D.inches;
    for (int i = 0; i < size; ++i) {
        output << Vec.coordinates_[i];
        if(i < size - 1){
            output << ",";
        }
    }
    output << ")";
    return output;
}

template <class T,int size>
T InnerProduct(const TempVec<T,size>& first,const TempVec<T,size>& second){
    T innerProduct;
    for (int i = 0; i < size; ++i) {
        if(i == 0){
            innerProduct = InnerProduct(first.coordinates_[i],second.coordinates_[i]);
            continue;
        }
        innerProduct = innerProduct + InnerProduct(first.coordinates_[i],second.coordinates_[i]);
    }
    return innerProduct;
};

template <class T,int size>
T SqNorm(const TempVec<T,size>& vec){
    return InnerProduct(vec,vec);
};
template <class T,int size>
T SqDistance(const TempVec<T,size>& first,const TempVec<T,size>& second){
    TempVec<T,size> tmpVec = first - second;
    return SqNorm(tmpVec);
};



#endif

