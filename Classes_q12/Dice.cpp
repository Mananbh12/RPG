#include "Dice.h"

RPG::Dice::Dice(int face): nbFaces(face){
    if(nbFaces%6!=0){
        throw std::invalid_argument("Pas un multiple de 6 :");
    }
}


int RPG::Dice::getValue() const{
    return std::rand()%(getMaxValue()-getMinValue()+1)+getMinValue();
}


int RPG::Dice::getMaxValue() const{
    return this->nbFaces;
}


int RPG::Dice::getMinValue() const{
    return (this->nbFaces/6);
}

void RPG::Dice::to_stream(std::ostream& o)const{
    o << getMinValue() << " - " << getMaxValue();
}

RPG::Dice* RPG::Dice::clone()const{
    return new Dice(this->nbFaces);
}



