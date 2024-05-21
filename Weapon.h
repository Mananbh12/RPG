#ifndef CLASS_WEAPON
#define CLASS_WEAPON
    #include "Printable.h"
    #include "IntegerItem.h"
    #include <memory>
    #include <iostream>
    #include <iomanip>
    namespace RPG
    {
        class Weapon : public Printable{
        protected:
            std::unique_ptr<IntegerItem> damage;
        public:

            Weapon(IntegerItem *p):damage(p){}

            std::unique_ptr<IntegerItem>& getDamage(){
                return this->damage;
            }
            void to_stream(std::ostream& o) const{
                o << "Damage : " << *damage << std::endl;
            }
        };
    }
#endif
