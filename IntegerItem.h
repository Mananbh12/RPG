#ifndef CLASS_INTEGERITEM
#define CLASS_INTEGERITEM
    #include <iostream>
    #include <string>
    #include "Printable.h"
    #include "damageable.h"
    namespace RPG
    {
        class IntegerItem : public Printable{
        
        public:
            virtual int getValue() const= 0;
            virtual int getMaxValue() const= 0;
            virtual int getMinValue() const= 0;
            virtual ~IntegerItem(){}; //destructeur virtuel
        };
    }
#endif        