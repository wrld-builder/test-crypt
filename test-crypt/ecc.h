#ifndef ECC_H
#define ECC_H

#include "exception.h"
#include <cmath>
#include <complex>

using Exceptions::FieldElementSpace::PrimeNotEqual;
using Exceptions::FieldElementSpace::OtherFieldElementIsEmpty;
using Exceptions::FieldElementSpace::NumberHigherPrimeOrLessZero;
using Exceptions::PointSpace::PointNotOnCurve;
using Exceptions::PointSpace::PointIsEmpty;
using Exceptions::PointSpace::PointIsInfinity;

class FieldElement {
public:
    explicit FieldElement(const int number, const int prime);

    explicit inline FieldElement(){};

    ~FieldElement(){};

    FieldElement operator+(FieldElement* other);

    FieldElement operator-(FieldElement* other);

    FieldElement operator*(FieldElement* other);

    FieldElement operator/(FieldElement* other);

    bool operator==(FieldElement* other);

    inline int getNumberFieldElement() const { return this->number; }

    inline int getPrimeFieldElement() const { return this->prime; }

    FieldElement powFieldElement(const int& exponent) const;    //pow number

private:
    int number = 0;
    int prime = 0;
};

class Point {     // eliptic curve interface
public:
    explicit Point(const int x, const int y, const int a, const int b);

    bool operator==(Point* other);

private:
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
};

#endif // ECC_H
