#include "IntegerValue.h"


int RPG::IntegerValue::getValue() const{
    return value;
}

int RPG::IntegerValue::getMaxValue() const{
    return value;
}

int RPG::IntegerValue::getMinValue() const{
    return value;
}

void RPG::IntegerValue::to_stream(std::ostream& o) const{
    o << this->getValue() << std::endl;
}
