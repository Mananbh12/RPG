#ifndef CLASS_DAMAGEABLE
#define CLASS_DAMAGEABLE
    #include <iostream>
    #include <string>
    namespace RPG
    {
        class Damageable{
        protected:
            double m_hitPoints;
            std::string m_name;

        public:

            Damageable(std::string n, double hp): m_hitPoints(hp), m_name(n){}

            Damageable(Damageable& autre){
                this->m_name = autre.getName();
                this->healRepair(autre.gethitPoint());
            }

            double gethitPoint(){
                return m_hitPoints;
            }

            std::string getName(){
                return m_name;
            }

            void setName(std::string n){
                m_name = n;
            }

            void damage(int damage){
                
                if(m_hitPoints<=damage){
                    m_hitPoints = 0.0;    
                }else{
                    m_hitPoints = m_hitPoints-damage;
                }

            }

            bool isDead(){
                if(this->m_hitPoints==0){
                    return 1;
                }else{
                    return 0;
                }
            }

            void healRepair(int heal){
                if(this->isDead()!=1){
                    m_hitPoints+=heal;
                }
            }

        };
    }

#endif
