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
    // pair for adding infinity point on eliptic curve
    // true - normal point
    // false - infinity point
    explicit Point(const std::pair<bool, const int> x, const std::pair<bool, const int> y, const int a, const int b);

    bool operator==(Point* other);

    Point operator+(Point* other);

    inline int getXCoordinate() const { return this->x.second; }

    inline int getYCoordinate() const { return this->y.second; }

    inline int getACoefficient() const { return this->a; }

    inline int getBCoefficient() const { return this->b; }

private:
    std::pair<bool, int> x = {};
    std::pair<bool, int> y = {};
    int a = 0;
    int b = 0;
};

#endif // ECC_H
