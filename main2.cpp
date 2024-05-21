#include "creature.h"
#include "Dice.h"
#include "Race.h"
#include "IntegerValue.h"
#include "Crafted_weapon.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iomanip>

int main() {
	using namespace RPG;
	Weapon* w1=new CraftedWeapon(new Dice(66), "Sword", 100, 100);
	Weapon* w2=new Weapon(*w1);
	std::cout<<*w1<<std::endl;
	std::cout<<*w2<<std::endl;
	return 0;
}