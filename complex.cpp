//
// Created by Omri Carmi on 22/01/2017.
//

#include "complex.h"

complex::complex(int real, int img) {

    re_ = real;
    im_ = img;

}

//complex &complex::operator+=(const complex &rhs) {
//    re_ += rhs.re_;
//    im_ += rhs.im_;
//    return *this;
//}

complex complex::operator+(const complex &rhs) const{
    return complex(re_+rhs.re_,im_+rhs.im_);
}

complex complex::operator-(const complex &rhs) const{
    return complex(re_-rhs.re_,im_-rhs.im_);
}

//complex &complex::operator-=(const complex &rhs) {
//    re_ -= rhs.re_;
//    im_ -= rhs.im_;
//    return *this;
//}

complex complex::operator*(const complex &rhs) const{
    return complex(re_*rhs.re_ - im_*rhs.im_,im_*rhs.re_ + re_*rhs.im_);
}

//complex &complex::operator*=(const complex &rhs) {
//    re_ *= re_*rhs.re_ - im_*rhs.im_;
//    im_ *= im_*rhs.re_ + re_*rhs.im_;
//    return *this;
//}

complex conj(const complex& c){
    return complex(c.re_,-1*c.im_);
}

ostream& operator<<(ostream& ro,const complex c){
    c.print(ro);
    return ro;
}

void complex::print(ostream &ro) const {
    //if num is 0
    if(re_ == 0 && im_ == 0){
        ro << "0";
        return;
    }
    //print re if exist and image not
    if(re_ != 0 && im_ == 0){
        ro << re_;
    }
    //print image if exist and real not
    if(re_ == 0 && im_ != 0){
        printImg(ro);
    }
    //print both if both exists
    if(re_ != 0 && im_ != 0){
        ro << re_;
        if(im_ > 0){
            ro << "+";
        }
        printImg(ro);
    }
}

void complex::printImg(ostream &ro) const {
    if(im_ == 0) return;

    if(im_ == -1){
        ro << "-i";
        return;
    }

    if(im_ == 1){
        ro << "i";
        return;
    }

    ro << im_ << "i";
}

complex InnerProduct(const complex &x, const complex &y) {
    return x*conj(y);
}

complex SqNorm(const complex &c) {
    return InnerProduct(c,c);
}

complex SqDistance(const complex &x, const complex &y) {
    return SqNorm(x-y);
}
