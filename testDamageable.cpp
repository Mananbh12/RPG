#include <iostream>
#include <string>
#include "damageable.h"
using namespace RPG;
int main(){
	Damageable k("Knight",12);
	k.damage(8);
	std::cout << k.getName() << " HP : " <<k.gethitPoint() << std::endl;
	Damageable p("Prêtre-médecin", 8);
	k.healRepair(6);
	std::cout << k.getName() << " HP : " <<k.gethitPoint() << std::endl;
	Damageable d("Dragon", 100);
	k.damage(100);
	std::cout << k.getName() << " Est mort ? : "<< k.isDead() << std::endl;
	k.healRepair(8);
	std::cout << k.getName() << " Est mort ? : "<< k.isDead() << std::endl;
}