#ifndef CLASS_UNIQUE_WEAPON
#define CLASS_UNIQUE_WEAPON
    #include <iostream>
    #include <string>
    #include "Printable.h"
    #include "damageable.h"
    #include "IntegerItem.h"
    #include "Crafted_weapon.h"
    #include "item.h"
    #include "Weapon.h"
    #include <cstdlib>
    #include <stdexcept>
    #include <memory>
    namespace RPG
    {
        class UniqueWeapon: public Weapon, public Item{
        public:
            UniqueWeapon(std::string n, int v, double hp, IntegerItem *p): Item(n, v, hp), Weapon(p){}
            ~UniqueWeapon();
            void to_stream(std::ostream& o){
                o << this->getName() << "*** ";
                Weapon::to_stream(o); 
                o << " | " << this->value << ")" << std::endl;
            }
        };
    #endif
    }