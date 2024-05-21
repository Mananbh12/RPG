#ifndef CLASS_CREATURE
#define CLASS_CREATURE
    #include <iostream>
    #include <string>
    #include "Printable.h"
    #include "damageable.h"
    #include "Race.h"
    #include <memory>
    namespace RPG
    {
        class Creature : public Damageable, public Printable{
        private:
            std::shared_ptr<Race> creatureRace;
            int physic;
            int mental;
        public:
            Creature(std::string name, std::shared_ptr<Race> race):Damageable(name, race->getPhysic()->getValue()), creatureRace(race), physic(race->getPhysic()->getValue()),mental(race->getMental()->getValue()){}

            ~Creature(){}
            
            int getM_mental(){
                return this->mental;
            }
            
            void to_stream(std::ostream& o) const{
                    o << m_name << "'s current HP is " 
                    << m_hitPoints << std::endl;
            }
    };
    #endif
}
/*Creature(Creature& autre): Damageable(autre) {            
                this->setName(autre.getName());
                this->healRepair(autre.gethitPoint());
                this->physic = autre.physic;
                this->mental = autre.mental;*/