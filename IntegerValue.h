#ifndef CLASS_INTEGER_VALUE
#define CLASS_INTEGER_VALUE

#include "IntegerItem.h"
#include <iostream>

namespace RPG{
    
    class IntegerValue : public IntegerItem {
        protected:
            int value;
        public:
            IntegerValue(int v):value(v){}


            int getValue() const{
                return value;
            }

            int getMaxValue() const{
                return value;
            }

            int getMinValue() const{
                return value;
            }

            void to_stream(std::ostream& o) const{
                o << this->getValue() << std::endl;
            }

    };
}
#endif