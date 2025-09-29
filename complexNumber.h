#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class complexNumber {
private:
        double real;
        double im;
    
public:
        // Constructors
        complexNumber();
        complexNumber(double r, double i = 0);

        // Setters
        void setReal(double r);
        void setIm(double i);

        // Getters
        double getReal() const;
        double getIm() const;

        // Magnitude or Modulus
        double getModulus() const;

        //Print "real + i im"
        void print()const;

};

        // >> and << Overloading
std::istream& operator>>(std::istream& in, complexNumber& c);
std::ostream& operator<<(std::ostream& out, const complexNumber& c);

        // Mathematical Operations
complexNumber operator+(const complexNumber& lhs, const complexNumber& rhs);
complexNumber operator-(const complexNumber& lhs, const complexNumber& rhs);
complexNumber operator*(const complexNumber& lhs, const complexNumber& rhs);
complexNumber operator/(const complexNumber& lhs, const complexNumber& rhs);

#endif