#ifndef _TEMPVEC_H
#define _TEMPVEC_H

#include <iostream>

using namespace std;

template <class T,int size>
class TempVec {
 public:
  TempVec(){}
 protected:
  T coordinates_[size];
};


#endif
