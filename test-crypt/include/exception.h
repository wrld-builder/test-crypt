#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <iostream>

// debug macros
#define DEBUG(x) do { std::cerr << x; } while (0)

namespace Exceptions {  // namespace Exceptions
namespace FieldElementSpace {   // namespace FieldElementSpace

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

} //namespace FieldElementSpace

namespace PointSpace {   // namespace PointSpace

class PointNotOnCurve : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: point not on curve";
    }
};

class PointIsEmpty : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: other curve is empty";
    }
};

class PointIsInfinity : public std::exception {
public:
    inline const char* what() const noexcept override {
        return "Exception: point is infnity";
    }
};

} // namespace PointSpace

} // namespace Exceptions

#endif // EXCEPTION_H
