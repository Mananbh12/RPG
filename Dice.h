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
    private:
        int nbFaces;
    public:
        Dice(int face=6): nbFaces(face){
        if(nbFaces%6!=0){
            throw std::invalid_argument("Pas un multiple de 6 :");
        }
    }
    int getValue() const{
        return std::rand()%(getMaxValue()-getMinValue()+1)+getMinValue();
    }

    int getMaxValue() const{
        return this->nbFaces;
    }


    int getMinValue() const{
        return (this->nbFaces/6);
    }

    void to_stream(std::ostream& o)const{
        o << getMinValue() << " - " << getMaxValue();
    }

    };
}
#endif