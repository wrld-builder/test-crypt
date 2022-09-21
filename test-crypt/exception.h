#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <iostream>
#define DEBUG(x) do { std::cerr << x; } while (0)

namespace Exceptions {

class NumberHigherPrimeOrLessZero : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: number higher than prime or less than zero('0')";
    }
};

class OtherFieldElementIsEmpty : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: other field element is empty";
    }
};

class PrimeNotEqual : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: cannot do this operation. Primes not equal";
    }
};

}

#endif // EXCEPTION_H
