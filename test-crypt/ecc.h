#ifndef ECC_H
#define ECC_H

#include "exception.h"
#include <cmath>
#include <complex>

class FieldElement {
public:
    explicit FieldElement(const int number, const int prime);

    explicit inline FieldElement(){};

    ~FieldElement(){};

    inline FieldElement operator+(FieldElement* other) {
        try {
            if(this->prime != other->prime) throw Exceptions::PrimeNotEqual();

            auto result = (this->number + other->number) % this->prime;
            return FieldElement(result, prime);
        } catch(Exceptions::PrimeNotEqual& exception) {
            DEBUG(exception.what());
        }

        return FieldElement();
    }

    inline FieldElement operator-(FieldElement* other) {
        try {
            if(this->prime != other->prime) throw Exceptions::PrimeNotEqual();

            auto result = (this->number - other->number) % this->prime;
            return FieldElement(result, prime);

        } catch(Exceptions::PrimeNotEqual& exception) {
            DEBUG(exception.what());
        }

        return FieldElement();
    }

    inline FieldElement operator*(FieldElement* other) {
        try {
            if(this->prime != other->prime) throw Exceptions::PrimeNotEqual();

            auto result = (this->number * other->number) % this->prime;
            return FieldElement(result, prime);

        } catch(Exceptions::PrimeNotEqual& exception) {
            DEBUG(exception.what());
        }

        return FieldElement();
    }

    inline FieldElement operator/(FieldElement* other) {
        try {
            if(this->prime != other->prime) throw Exceptions::PrimeNotEqual();

            auto result = this->number * static_cast<long int>((std::pow(other->number, this->prime - 2))) % this->prime;
            return FieldElement(result, prime);

        } catch(Exceptions::PrimeNotEqual& exception) {
            DEBUG(exception.what());
        }

        return FieldElement();
    }

    inline int getNumberFieldElement() const { return this->number; }

    inline int getPrimeFieldElement() const { return this->prime; }

    bool isEqualFieldElement(FieldElement* other) const;      //equal two field elements

    FieldElement powFieldElement(const int& exponent) const;    //pow number

private:
    int number = 0;
    int prime = 0;
};

#endif // ECC_H
