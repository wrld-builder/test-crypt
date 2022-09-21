#include "ecc.h"
#include "exception.h"

FieldElement::FieldElement(const int number, const int prime) {
    try {
        if(number > prime || number < 0) throw Exceptions::NumberHigherPrimeOrLessZero();

        this->number = number;
        this->prime = prime;
    } catch(Exceptions::NumberHigherPrimeOrLessZero& exception) {
        DEBUG(exception.what());
    }
}

bool FieldElement::isEqualFieldElement(FieldElement *other) const {
    try {
        if(other == nullptr) throw Exceptions::OtherFieldElementIsEmpty();

        if(this->number == other->number && this->prime == other->prime) return true;
        else return false;
    }  catch (Exceptions::OtherFieldElementIsEmpty& exception) {
        DEBUG(exception.what());
    }

    return false;
}

FieldElement FieldElement::powFieldElement(const int& exponent) const {
    auto result = static_cast<long int>(std::pow(this->number, exponent)) % this->prime;
    return FieldElement(result, this->prime);
}
