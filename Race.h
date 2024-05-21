#ifndef CLASS_RACE
#define CLASS_RACE
    #include <iostream>
    #include <string>
    #include "Printable.h"
    #include "damageable.h"
    #include "IntegerItem.h"
    #include "item.h"
    #include "Crafted_weapon.h"
    #include "Weapon.h"
    #include <cstdlib>
    #include <stdexcept>
    #include <memory>
    namespace RPG
    {
        class Race: Printable{
        private:
            std::unique_ptr<IntegerItem> physicFormula;
            std::unique_ptr<IntegerItem> mentalFormula;
        public:

            Race(IntegerItem *phy, IntegerItem *men):physicFormula(phy), mentalFormula(men) {}

            std::unique_ptr<IntegerItem>& getPhysic(){
                return this->physicFormula;
            }
            std::unique_ptr<IntegerItem>& getMental(){
                return this->mentalFormula;
            }
            void to_stream(std::ostream o){
                o << "Base HP: " << getPhysic() << " | " getMental() << std::endl;
            }
        };
    }
#endif