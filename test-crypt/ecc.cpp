#include "ecc.h"
#include "exception.h"

FieldElement::FieldElement(const int number, const int prime) {
    try {
        if(number > prime || number < 0) throw NumberHigherPrimeOrLessZero();

        this->number = number;
        this->prime = prime;
    } catch(NumberHigherPrimeOrLessZero& exception) {
        DEBUG(exception.what());
    }
}

FieldElement FieldElement::operator+(FieldElement *other) {
    try {
        if(this->prime != other->prime) throw PrimeNotEqual();

        auto result = (this->number + other->number) % this->prime;
        return FieldElement(result, prime);
    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
    }

    return FieldElement();
}

FieldElement FieldElement::operator-(FieldElement *other) {
    try {
        if(this->prime != other->prime) throw PrimeNotEqual();

        auto result = (this->number - other->number) % this->prime;
        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
    }

    return FieldElement();
}

FieldElement FieldElement::operator*(FieldElement *other) {
    try {
        if(this->prime != other->prime) throw PrimeNotEqual();

        auto result = (this->number * other->number) % this->prime;
        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
    }

    return FieldElement();
}

FieldElement FieldElement::operator/(FieldElement *other) {
    try {
        if(this->prime != other->prime) throw PrimeNotEqual();

        auto result = this->number * static_cast<long int>((std::pow(other->number, this->prime - 2))) % this->prime;
        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
    }

    return FieldElement();
}

bool FieldElement::operator==(FieldElement* other) {
    try {
        if(other == nullptr) throw OtherFieldElementIsEmpty();

        if(this->number == other->number && this->prime == other->prime) return true;
        else return false;
    }  catch (OtherFieldElementIsEmpty& exception) {
        DEBUG(exception.what());
    }

    return false;
}

FieldElement FieldElement::powFieldElement(const int& exponent) const {
    auto result = static_cast<long int>(std::pow(this->number, exponent)) % this->prime;
    return FieldElement(result, this->prime);
}

Point::Point(const int x, const int y, const int a, const int b) {
    try {
        if(std::pow(y, 2) != std::pow(x, 3) + a * x + b) throw PointNotOnCurve();

        try {
            if(sizeof(x) == 0 && sizeof(y) == 0) throw PointIsInfinity();

            this->x = x;
            this->y = y;
            this->a = a;
            this->b = b;
        } catch(PointIsInfinity& exception) {
            DEBUG(exception.what());
            return;
        }
    }  catch (const PointNotOnCurve& exception) {
        DEBUG(exception.what());
    }
}

bool Point::operator==(Point *other) {
    try {
        if(other == nullptr) throw PointIsEmpty();

        if(this->x == other->x && this->y == other->y && this->a == other->a && this->b == other->b) return true;
        else return false;
    } catch(const PointIsEmpty& exception) {
        DEBUG(exception.what());
    }

    return false;
}
