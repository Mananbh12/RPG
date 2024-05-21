#ifndef CLASS_ITEM
#define CLASS_ITEM
    #include <iostream>
    #include <string>
    #include "damageable.h"
    namespace RPG
    {
        class Item : public Damageable{
        protected:
            int value;
        public:
            Item(std::string n, int v, double hp): Damageable(n, hp), value(v){}
            ~Item();
        };
    }
#endif