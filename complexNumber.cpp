#include "complexNumber.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <cstdlib>

// Deafault constructor: 0 + i 0 
complexNumber::complexNumber() : real(0.0), im(0.0){}

// Constructor with values
complexNumber::complexNumber(double r, double i) : real(r), im(i) {}

// Setters
void complexNumber::setReal(double r) {real=r;}
void complexNumber::setIm(double i){im = i;}

//Getters
double complexNumber::getReal() const {return real;}
double complexNumber::getIm() const {return im;}

// Modulus
double complexNumber::getModulus() const {
    return std::sqrt(real * real + im * im);
}

//Printing the number 
void complexNumber::print() const {
    if (real == 0.0 && im == 0.0) {
        std::cout << "0\n";
        return;
    }

    bool haveReal = (real != 0.0);
    bool haveIm   = (im   != 0.0);

    if (haveReal) {
        std::cout << real;
        if (haveIm) {
            std::cout << (im >= 0 ? "+" : "-") << std::fabs(im) << "i";
        }
        std::cout << "\n";
        return;
    }

    // only imaginary part
    if (im >= 0) std::cout << "+" << im << "i\n";
    else         std::cout << "-" << std::fabs(im) << "i\n";
    
}

//Addition
complexNumber operator+(const complexNumber& lhs, const complexNumber& rhs) {
    return complexNumber(lhs.getReal() + rhs.getReal(),
                         lhs.getIm()   + rhs.getIm());
}

//Subtraction
complexNumber operator-(const complexNumber& lhs, const complexNumber& rhs) {
    return complexNumber(lhs.getReal() - rhs.getReal(),
                         lhs.getIm()   - rhs.getIm());
}

//Multiplication
complexNumber operator*(const complexNumber& lhs, const complexNumber& rhs) {
    double r = lhs.getReal() * rhs.getReal() - lhs.getIm() * rhs.getIm();
    double i = lhs.getReal() * rhs.getIm()   + lhs.getIm() * rhs.getReal();
    return complexNumber(r, i);
}

//Division
complexNumber operator/(const complexNumber& lhs, const complexNumber& rhs) {
    double denom = rhs.getReal() * rhs.getReal() + rhs.getIm() * rhs.getIm();   //denominator
    if (denom == 0.0) {
        throw std::runtime_error("Division by zero complex number");
    }
    double r = (lhs.getReal() * rhs.getReal() + lhs.getIm() * rhs.getIm()) / denom;
    double i = (lhs.getIm() * rhs.getReal() - lhs.getReal() * rhs.getIm()) / denom;
    return complexNumber(r, i);
}

//<< overloading
std::ostream& operator<<(std::ostream& out, const complexNumber& c){
    out << c.getReal();
    if (c.getIm() >= 0)
        out << "+" << c.getIm() << "i";
    else
        out << c.getIm() << "i"; 
    return out;
} 

//>> overloading

std::istream& operator>>(std::istream& in, complexNumber& c) {
    std::string s;
    if (!(in >> s)) { std::cerr << "Invalid Format. Program Terminated."; std::exit(EXIT_FAILURE); }

    double r = 0, im = 0;

    if (!s.empty() && s.back() == 'i') {
        std::string t = s.substr(0, s.size() - 1);
        if (t.empty() || t == "+" || t == "-") {
            im = (t == "-") ? -1.0 : 1.0;
        } else {
            size_t pos = std::string::npos;
            for (size_t i = 1; i < t.size(); ++i) if (t[i] == '+' || t[i] == '-') { pos = i; break; }
            if (pos == std::string::npos) {
                std::istringstream si(t);
                if (!(si >> im) || (si >> std::ws, si.peek() != EOF)) { std::cerr << "Invalid Format. Program Terminated."; std::exit(EXIT_FAILURE); }
            } else {
                std::istringstream sr(t.substr(0, pos)), si(t.substr(pos + 1));
                char sign = t[pos];
                if (!(sr >> r) || (sr >> std::ws, sr.peek() != EOF)) { std::cerr << "Invalid Format. Program Terminated."; std::exit(EXIT_FAILURE); }
                if (!(si >> im) || (si >> std::ws, si.peek() != EOF)) { std::cerr << "Invalid Format. Program Terminated."; std::exit(EXIT_FAILURE); }
                if (sign == '-') im = -im;
            }
        }
    } else {
        std::istringstream sr(s);
        if (!(sr >> r) || (sr >> std::ws, sr.peek() != EOF)) { std::cerr << "Invalid Format. Program Terminated."; std::exit(EXIT_FAILURE); }
        im = 0;
    }

    c.setReal(r);
    c.setIm(im);
    return in;
}
