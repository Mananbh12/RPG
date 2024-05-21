#ifndef CLASS_DICE
#define CLASS_DICE

    #include <iostream>
    #include <string>
    #include "Printable.h"
    #include "damageable.h"
    #include "IntegerItem.h"
    #include <cstdlib>
    #include <stdexcept>

namespace RPG{
    
    class Dice : public IntegerItem{
        protected:
            int nbFaces;
        public:
            Dice(int n=6);

            int getMaxValue()const override;
            int getMinValue()const override;

            int getValue()const override;

            Dice* clone()const override;

            void to_stream(std::ostream& o)const override;   
        };
}
#endif