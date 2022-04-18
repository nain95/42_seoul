#include "Fixed.hpp"

Fixed::Fixed()
{
    this->RawBits = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int val)
{
    RawBits = (val << Fixed::bits);
}

Fixed::Fixed(const float val)
{
    RawBits = roundf(val * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed& f)
{
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    this->RawBits = f.getRawBits();
    return (*this);
}

void Fixed::setRawBits(const int raw)
{
    this->RawBits = raw;
}

int Fixed::getRawBits(void) const
{
    return this->RawBits;
}

std::ostream &operator<<(std::ostream &ost, const Fixed& f)
{
    ost << f.toFloat();
    return (ost);
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->RawBits) / (1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
    return (this->RawBits >> Fixed::bits);
}


bool Fixed::operator==(const Fixed& f) const {return (this->getRawBits() == f.getRawBits());}
bool Fixed::operator!=(const Fixed& f) const {return (this->getRawBits()!= f.getRawBits());}
bool Fixed::operator>(const Fixed& f) const {return (this->getRawBits() > f.getRawBits());}
bool Fixed::operator<(const Fixed& f) const {return (this->getRawBits() < f.getRawBits());}
bool Fixed::operator>=(const Fixed& f) const {return (this->getRawBits() >= f.getRawBits());}
bool Fixed::operator<=(const Fixed& f) const {return (this->getRawBits() <= f.getRawBits());}


Fixed Fixed::operator+(const Fixed& f) {
    Fixed tmp(this->toFloat() + f.toFloat());
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& f) {
    Fixed tmp(this->toFloat() - f.toFloat());
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

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
  if (a > b)
    return (b); 
  return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
  if (a > b) 
    return (b); 
  return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
  if (a > b)
    return (a); 
  return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
  if (a > b)
    return (a);
  return (b);
}
