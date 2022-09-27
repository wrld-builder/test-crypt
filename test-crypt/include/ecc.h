#ifndef ECC_H
#define ECC_H

#include "exception.h"
#include <cmath>
#include <complex>
#include <memory>

using Exceptions::FieldElementSpace::PrimeNotEqual;
using Exceptions::FieldElementSpace::OtherFieldElementIsEmpty;
using Exceptions::FieldElementSpace::NumberHigherPrimeOrLessZero;
using Exceptions::PointSpace::PointNotOnCurve;
using Exceptions::PointSpace::PointIsEmpty;
using Exceptions::PointSpace::PointIsInfinity;

class MathBase {
public:
    int modexp(const int x, const int y, const int N) const;
};

class FieldElement : public MathBase {
public:
    explicit FieldElement(const long long number, const long long prime);

    explicit inline FieldElement(){};

    inline ~FieldElement(){};

    FieldElement operator+(const FieldElement other);

    FieldElement operator-(const FieldElement other);

    FieldElement operator*(const FieldElement other);

    FieldElement operator/(const FieldElement other);

    bool operator==(const FieldElement *other);

    bool operator!=(const FieldElement *other);

    inline int getNumberFieldElement() const { return this->number; }

    inline int getPrimeFieldElement() const { return this->prime; }

    FieldElement powFieldElement(const int exponent);    //pow number

private:
    long long number = 0;
    long long prime = 0;
};

class Point {     // eliptic curve interface
public:    
    // ECC with extension fields constructor
    explicit Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);

    inline ~Point(){};

    Point operator+(Point other);

    inline std::shared_ptr<FieldElement> getX() const { return x; }

    inline std::shared_ptr<FieldElement> getY() const { return y; }

private:
    FieldElement a;
    FieldElement b;
    std::shared_ptr<FieldElement> x = nullptr;
    std::shared_ptr<FieldElement> y = nullptr;
};

#endif // ECC_H
