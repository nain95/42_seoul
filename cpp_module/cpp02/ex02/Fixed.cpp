#include "Fixed.hpp"

Fixed::Fixed() : intVal(0) {}
Fixed::~Fixed(){}
Fixed::Fixed(int const val) : intVal(val << Fixed::bits){}
Fixed::Fixed(float const val) : intVal(roundf(val * (1 << Fixed::bits))){}
Fixed::Fixed(const Fixed& f) : intVal(f.getIntVal()){}

bool Fixed::operator==(const Fixed& f) const {return (this->getIntVal() == f.getIntVal());}
bool Fixed::operator!=(const Fixed& f) const {return (this->getIntVal()!= f.getIntVal());}
bool Fixed::operator>(const Fixed& f) const {return (this->getIntVal() > f.getIntVal());}
bool Fixed::operator<(const Fixed& f) const {return (this->getIntVal() < f.getIntVal());}
bool Fixed::operator>=(const Fixed& f) const {return (this->getIntVal() >= f.getIntVal());}
bool Fixed::operator<=(const Fixed& f) const {return (this->getIntVal() <= f.getIntVal());}

Fixed& Fixed::operator=(const Fixed& f) {
    this->intVal = f.getIntVal();
    return (*this);
}

Fixed Fixed::operator+(const Fixed& f) {
    Fixed tmp(*this); 
    tmp.setIntVal(tmp.getIntVal() + f.getIntVal()); 
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& f) {
    Fixed tmp(*this); 
    tmp.setIntVal(tmp.getIntVal() - f.getIntVal()); 
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& f) {
    Fixed tmp(this->toFloat() * f.toFloat()); 
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& f) {
    Fixed tmp(this->toFloat() / f.toFloat()); 
    return (tmp);
}

Fixed& Fixed::operator++(void) {
  ++RawBits;
  return *this;
}

Fixed& Fixed::operator--(void) {
  --RawBits;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;

  ++RawBits;
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;

  --RawBits;
  return temp;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {if (a > b) return (b); return (a);}
Fixed &Fixed::min(Fixed &a, Fixed &b) {if (a > b) return (b); return (a);}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {if (a > b) return (a); return (b);}
Fixed &Fixed::max(Fixed &a, Fixed &b) {if (a > b) return (a); return (b);}

int Fixed::getRawBits() const{return RawBits;}
void Fixed::setRawBits(const int val){RawBits = val;}
float Fixed::toFloat(void) const{return static_cast<float>(this->RawBits) / (1 << Fixed::bits);}
int Fixed::toInt(void) const{return (this->RawBits >> Fixed::bits);}

std::ostream &operator<<(std::ostream &ost, Fixed const &f){ost << f.toFloat(); return (ost);}