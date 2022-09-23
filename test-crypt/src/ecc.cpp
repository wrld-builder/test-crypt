#include "../include/ecc.h"
#include "../include/exception.h"
#include <cstdlib>

FieldElement::FieldElement(const int number, const int prime) {
    try {
        if(number > prime || number < 0) throw NumberHigherPrimeOrLessZero();

        this->number = number;
        this->prime = prime;
    } catch(NumberHigherPrimeOrLessZero& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }
}

FieldElement FieldElement::operator+(FieldElement *other) {
    try {
        if(this->prime != other->prime) throw PrimeNotEqual();

        auto result = (this->number + other->number) % this->prime;
        return FieldElement(result, prime);
    } catch(PrimeNotEqual& exception) {
        DEBUG(exception.what());
        std::exit(1);
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
        std::exit(1);
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
        std::exit(1);
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
        std::exit(1);
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
        std::exit(1);
    }

    return false;
}

FieldElement FieldElement::powFieldElement(const int& exponent) const {
    auto result = static_cast<long int>(std::pow(this->number, exponent)) % this->prime;
    return FieldElement(result, this->prime);
}

Point::Point(const std::pair<bool, const int> x, const std::pair<bool, const int> y, const int a, const int b) {
    try {
        if(std::pow(y.second, 2) != std::pow(x.second, 3) + a * x.second + b) throw PointNotOnCurve();

        try {
            if(x.first == false && y.first == false) throw PointIsInfinity();

            this->x = x;
            this->y = y;
            this->a = a;
            this->b = b;
        } catch(PointIsInfinity& exception) {
            DEBUG(exception.what());
            std::exit(1);
        }
    }  catch (const PointNotOnCurve& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }
}

bool Point::operator==(Point *other) {
    try {
        if(other == nullptr) throw PointIsEmpty();

        if(this->x == other->x && this->y == other->y && this->a == other->a && this->b == other->b) return true;
        else return false;
    } catch(const PointIsEmpty& exception) {
        DEBUG(exception.what());
        std::exit(1);
    }

    return false;
}

Point Point::operator+(Point *other) {
    try {
        if(this->a != other->a && this->b != other->b)
            throw std::exception();
        else if(this->x.second == other->x.second && this->y.second != other->y.second)
            return Point(std::make_pair(false, 0), std::make_pair(false, 0), this->a, this->b);
        else if(this == other && this->x.second == 0 && this->y.second == 0) {
            return Point(std::make_pair(false, 0), std::make_pair(false, 0), this->a, this->b);
        }

        else if(this->x.second != other->x.second) {
            auto incline = (other->y.second - this->y.second) / (other->x.second - this->x.second);
            auto new_x = std::pow(incline, 2) - this->x.second - other->x.second;
            auto new_y = incline * (this->x.second - new_x) - this->y.second;

            return Point(std::make_pair(true, new_x), std::make_pair(true, new_y), this->a, this->b);
        } else if(this == other) {
            auto incline = (3 * std::pow(this->x.second, 2) + this->a) / (2 * this->y.second);
            auto new_x = std::pow(incline, 2) - (2 * this->x.second);
            auto new_y = incline * (this->x.second - new_x) - this->y.second;

            return Point(std::make_pair(true, new_x), std::make_pair(true, new_y), this->a, this->b);
        }

        else if(!this->x.first)
            return *other;
        else if(!other->x.first)
            return *this;
    } catch(std::exception& exception) {
        DEBUG(exception.what() << " . Exception: points not on the same curve");
        std::exit(1);
    }

    std::exit(1);
}
