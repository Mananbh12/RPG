#include "creature.h"
#include "dice.h"
#include "race.h"
#include "integer_value.h"
#include "crafted_weapon.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iomanip>
int main() {
    srand(time(NULL));

    using namespace std;
    using namespace rpg;

    cout << "Welcome to the RPG!" << endl;
    cout << "-----------------------------------------------------" << endl;

    // Name Input
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    
    // Races
    std::vector<std::string> races={"Human","Orc","Elf","Dragonborn"};
    std::map<std::string,shared_ptr<Race>> playerRaces;
    playerRaces["Human"]=std::make_shared<Race>(new IntegerValue(20), new IntegerValue(20));
    playerRaces["Orc"]=std::make_shared<Race>(new IntegerValue(140), new IntegerValue(60));
    playerRaces["Elf"]=std::make_shared<Race>(new IntegerValue(70), new IntegerValue(150));
    playerRaces["Dragonborn"]=std::make_shared<Race>(new Dice(180), new Dice(126));


    
    // Race Selection
    int chosenRace = -1;
    cout << "Select a race" << endl;
    cout << "-----------------------------------------------------" << endl;
    for(unsigned int i=1; i<=races.size();i++)
		std::cout<<i<<" - "<<std::setw(10)<<std::left<<races[i-1]<<" - "<<*playerRaces[races[i-1]]<<std::endl;
    cout << "-----------------------------------------------------" << endl;
    // While the chosen race is incorrect
    while (chosenRace < 1 || chosenRace > 4)
        cin >> chosenRace;

    // Player Creation
    Creature player(playerName, playerRaces[races[chosenRace-1]]);
    
    //Weapons
    std::vector<Weapon*> playerWeapons={new CraftedWeapon(new Dice(66), "Infinity Bow", 100, 1000), new CraftedWeapon(new Dice(66),"Excalibur", 100, 3000),new CraftedWeapon(new IntegerValue(36), "Hellfire Spear", 100, 2000)};

    // Weapon Selection
    cout << "Select a weapon" << endl;
    cout << "-----------------------------------------------------" << endl;
	for(unsigned int i=1; i<=playerWeapons.size();i++)
		std::cout<<i<<" - "<<*playerWeapons[i-1]<<std::endl;
    cout << "-----------------------------------------------------" << endl;

    int chosenWeapon = -1;

    // While the chosen weapon is incorrect
    while (chosenWeapon < 1 || chosenWeapon > 3)
        cin >> chosenWeapon;    
    
    Weapon* playerWeapon=playerWeapons[chosenWeapon];
    // Boss Creation
    auto bossPhysic = new Dice(600);
    auto bossMental = new Dice(600);

    playerRaces["Valar"] =  std::make_shared<Race>(bossPhysic, bossMental);
    races.push_back("Valar");
    
    Creature finalBoss("The Dark Lord", playerRaces["Valar"]);

    // Main Loop
    bool stop = false;

    while (!stop) {
		cout << "-----------------------------------------------------" << std::endl;
        cout << player << endl;
        cout << finalBoss << endl;
        cout << "-----------------------------------------------------" << std::endl;

        // Player Action
        int chosenAction = -1;

        Dice playerRegen(player.getM_mental()-player.getM_mental()%6);

        cout << "What to do?" << endl;
        cout << "1 - Attack (" << playerWeapon->getDamage()->getMinValue() << "-" << playerWeapon->getDamage()->getMaxValue() << ")" << endl;
        cout << "2 - Heal   (" << playerRegen.getMinValue() << "-" << playerRegen.getMaxValue() << ")" << endl;
        cout << "3 - Exit" << endl;

        while (chosenAction < 1 || chosenAction > 3)
            cin >> chosenAction;
		cout << "-----------------------------------------------------" << std::endl;
        int damage = playerWeapon->getDamage()->getValue();
        int hp = playerRegen.getValue();

        switch (chosenAction) {
            case 1:
                finalBoss.damage(damage);
                break;
            case 2:
                player.healRepair(hp);
                break;
            case 3:
                stop = true;
                break;
            default:
                break;
        }

        if (!stop) {
            // Boss Action
            Dice bossAction(6);

            if (bossAction.getValue() == 2) {
                Dice bossRegen((finalBoss.getM_mental() - finalBoss.getM_mental()%12)/2 );
                int bossHp = bossRegen.getValue();
                finalBoss.healRepair(bossHp);
            } else {
                Dice bossDamageDice(48);
                int bossDamage = bossDamageDice.getValue();
                player.damage(bossDamage);
            }

            // End Message
            if (player.isDead()) {
                cout << "You lost... Try again!" << endl;
                stop = true;
            } else if (finalBoss.isDead()) {
                cout << "You defeated "<<finalBoss.getM_name()<<"! Congratulations!" << endl;
                stop = true;
            }
        }
        cout << "-----------------------------------------------------" << std::endl;
    }

    // Clean Up
    for(auto pw:playerWeapons)
		delete pw;
}
