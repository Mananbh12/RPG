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

            int getValue()const override;
            int getMaxValue()const override;
            int getMinValue()const override;

            IntegerValue* clone()const override;
            void to_stream(std::ostream& o)const override;
    };
}
#endif