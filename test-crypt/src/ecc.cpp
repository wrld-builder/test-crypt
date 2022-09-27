#include "../include/ecc.h"
#include "../include/exception.h"
#include <cstdlib>

FieldElement::FieldElement(const long long number, const long long prime) {
    try {
        if(number > prime || number < 0) throw NumberHigherPrimeOrLessZero();

        this->number = number;
        this->prime = prime;
    } catch(NumberHigherPrimeOrLessZero& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }
}

FieldElement FieldElement::operator+(const FieldElement other) {
    try {
        if(this->prime != other.prime) throw PrimeNotEqual();

        long long result = (this->number + other.number) % this->prime;
        if(result < 0) result += this->prime;

        return FieldElement(result, prime);
    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return FieldElement();
}

FieldElement FieldElement::operator-(const FieldElement other) {
    try {
        if(this->prime != other.prime) throw PrimeNotEqual();

        long long result = (this->number - other.number) % this->prime;
        if(result < 0) result += this->prime;

        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return FieldElement();
}

FieldElement FieldElement::operator*(const FieldElement other) {
    try {
        if(this->prime != other.prime) throw PrimeNotEqual();

        long long result = (this->number * other.number) % this->prime;
        if(result < 0) result += this->prime;

        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return FieldElement();
}

FieldElement FieldElement::operator/(const FieldElement other) {
    try {
        if(this->prime != other.prime) throw PrimeNotEqual();

        long long result = this->number * (static_cast<long long>((modexp(other.number, this->prime - 2, this->prime)))) % this->prime;
        if(result < 0) result += this->prime;

        return FieldElement(result, prime);

    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return FieldElement();
}

bool FieldElement::operator==(const FieldElement *other) {
    try {
        if(other == nullptr) throw OtherFieldElementIsEmpty();

        if(this->number == other->number && this->prime == other->prime) return true;
        else return false;
    }  catch (OtherFieldElementIsEmpty& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return false;
}

bool FieldElement::operator!=(const FieldElement *other) {
    try {
        if(other == nullptr) throw OtherFieldElementIsEmpty();

        if(this->number != other->number or this->prime != other->prime) return true;
        else return false;
    }  catch (OtherFieldElementIsEmpty& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return false;
}

FieldElement FieldElement::powFieldElement(const int exponent) {
    long long result = static_cast<long long>(std::pow(this->number, exponent)) % this->prime;
    if(result < 0) result += this->prime;

    return FieldElement(result, this->prime);
}

int MathBase::modexp(const int x, const int y, const int N) const {
  if (y == 0) return 1;
  int z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}


Point::Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b) {
    try {
        this->x = std::make_shared<FieldElement>(x);
        this->y = std::make_shared<FieldElement>(y);
        this->a = a;
        this->b = b;

        auto right_part = this->x->powFieldElement(3) + this->a * *this->x + this->b;
        auto left_part = this->y->powFieldElement(2);

        if(left_part != &right_part) throw PointNotOnCurve();
        else if(this->x == nullptr && this->y == nullptr) std::exit(1);
    } catch(PointNotOnCurve& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }
}

Point Point::operator+(Point other) {
    try {
        if(this->a != &other.a && this->b != &other.b) throw PointNotOnCurve();

        else if(this->x != other.x) {
            auto s = (*other.y - *this->y) / (*other.x - *this->x);
            auto new_x = s.powFieldElement(2) - *this->x - *other.x;
            auto new_y = s * (*this->x - new_x) - *this->y;

            return Point(new_x, new_y, this->a, this->b);
        } else if(this == &other) {
            auto s = (FieldElement(3, this->a.getPrimeFieldElement()) * this->x->powFieldElement(2) + this->a) / (FieldElement(2, this->a.getPrimeFieldElement()) * *this->y);
            auto x = s.powFieldElement(2) - FieldElement(2, this->a.getPrimeFieldElement()) * *this->x;
            auto y = s * (*this->x - x) - *this->y;

            return Point(x, y, this->a, this->b);
        }
    }  catch (PointNotOnCurve& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }
}
