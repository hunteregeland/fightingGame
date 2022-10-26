// author: hunter egeland
// this is my own work.

#include "gameplay.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/*

BUG/UPDATE TODO LIST: 

- name changer ✓
- enemy killed you logic ✓
- sword and armor multipliers ✓
- make sure every input has a checking system ✓
- saving to files 
- new or existing character screen 
- 0 potions logic ✓
- maybe higher level boss sharper sword ✓
- negative hp after defeated past 0 ✓
- only allow level upgrade after level boss is beaten ✓
- enemy has WAY too many health pots ✓
- user hp reset after continuing to fight bug ✓
- hp progress bar ✓
- write into file the new variables, check gameLoop ✓
- saves after ending shop, but also after next fight so     figure that out ✓
- CLEAN UP CODE
- SAVE CASH IN FILE

*/

// constructor
Gameplay::Gameplay()
{
}

// destructor
Gameplay::~Gameplay()
{
}

// function for displaying instructions to the user
void Gameplay::instructions() {
  cout << "\n-------------------------\nWelcome to...\n      ___                                                ___           ___           ___           ___           ___                   \n     /  /\\          ___           ___                   /  /\\         /  /\\         /  /\\         /  /\\         /  /\\          ___     \n    /  /  \\        /  /\\         /  /\\                 /  /  \\       /  /  \\       /  /  |       /  /  \\       /  /  \\        /__/\\    \n   /  / /\\ \\      /  /  \\       /  /  \\               /  / /\\ \\     /  / /\\ \\     /  / | |      /  / /\\ \\     /  / /\\ \\       \\  \\ \\   \n  /  / /  \\ \\    /  / /\\ \\     /  / /\\ \\             /  / /  \\ \\   /  / /  \\ \\   /  / /| |__   /  /  \\ \\ \\   /  /  \\ \\ \\       \\__\\ \\    \n /__/ / \\  \\ \\  /  /  \\ \\ \\   /  /  \\ \\ \\           /__/ / \\  \\ \\ /__/ / \\__\\ \\ /__/ /_|__  \\ /__/ /\\ \\_\\ | /__/ /\\ \\_\\ \\      /  /  \\ \n \\  \\ \\  \\__\\/ /__/ /\\ \\_\\ \\ /__/ /\\ \\_\\ \\          \\  \\ \\  \\__\\/ \\  \\ \\ /  / / \\__\\/  /  / / \\  \\ \\ \\ \\/ / \\__\\/  \\ \\/ /     /  / /\\ \\\n  \\  \\ \\       \\__\\/  \\ \\/ / \\__\\/  \\ \\/ /           \\  \\ \\        \\  \\ \\  / /        /  / /   \\  \\ \\_\\  /       \\__\\  /     /  / /__\\/\n   \\  \\ \\           \\  \\  /       \\  \\  /             \\  \\ \\        \\  \\ \\/ /        /  / /     \\  \\ \\/ /        /  / /     /__/ /     \n    \\  \\ \\           \\__\\/         \\__\\/               \\  \\ \\        \\  \\  /        /__/ /       \\__\\  /        /__/ /      \\__\\/      \n     \\__\\/                                              \\__\\/         \\__\\/         \\__\\/                       \\__\\/                  \n\n-------------------------\n\nIn CPP Combat, you will encounter 9 different enemies that you will have to fight.\nTo fight, you will have three options: attack, block, or use a health potion.\nYou will acquire swords that do more damage, armor that resists more damage, and health potions that help regain your health.\nEach fight will award cash that you can use in the shop.\nOnce you get the enemy to 0 hp, they will die and you will be presented with a choice:\n1) continue with your current hp and fight again for more cash\n2) exit the fight with your cash and enter the shop.\n\nIn the shop, you are able to use your cash to buy level upgrades, higher level swords and armor, and more health potions.\nNote that you can only buy a level upgrade after you've beaten a fight at your level.\nExit the shop to fight the next enemy and once you beat all ten, you win!\n\nYou have $500, Good luck.\n\n--------------------------------------------------\n" << endl;
}

// function to initialize hp for user
void Gameplay::initializeUHP() {
  setResistance(armorLvl); // set how much damage the user takes
  setSharpness(swordLvl);  // set how much damage the user deals
  sharp = 10 + sword; // set sharp to 10 + whatever the sword is set to in its function
}


// function to initialize hp for enemy
void Gameplay::initializeEHP() {

  // set enemy hp
  enemyHP = 100 + (shopLvl * 20);
    //enemyHP = 5; // testing function to set eHP low for easy kills

  // set enemy sword damage
  enemySharp = 10 + (shopLvl * 3);
}

// function to run gameplay
void Gameplay::gameplay(int sh, int c, int sw, int ar) {
  alive = true;
  fighting();
}

// function for all fighting logic
void Gameplay::fighting() {
  
  // intialize loop managers
  y = 0;
  z = 0;

  // create an enemy object and initialize its hp
  Enemy enemy;
  initializeEHP();

  // initialize the user's hp
  initializeUHP();
  userHP = 100 + armor;

  // output that the fight was joined
  cout << "\nYou have joined a Level " << shopLvl << " fight!\n--------------------------------\n\nA wild " << enemy.getName(shopLvl) << " has appeared with " << enemyHP << "hp!\nYou have " << userHP << " hp. (100 hp + " << armor << " armor)\n" << endl;


  // loop moves
  while (alive == true) {

    // get random enemy move & hp
    srand (time(NULL));
    int random;
    random = rand() % 9 + 1;
    if (random == 1 || random == 2 || random == 3 || random == 4) {
      enemyMove = 1;
    } else if (random == 5 || random == 6 || random == 7 || random == 8) {
      enemyMove = 2;
    } else if (random == 9) {
      enemyMove = 3;
    }


    // get player's move
    cout << "\n---------------\nMake your move.\n---------------\n\nEnter 'A' for attack, enter 'B' for block, enter 'P' to use a Health Potion.\nYou have " << potions << " Health Potions." << string( 7, '\n' ) << endl;
      cin >> move;
      cout << string( 100, '\n' );

    // make sure input is valid
    if (move == "A" || move == "a") {
      uMove = 1;
    } else if (move == "B" || move == "b") {
      uMove = 2;
    } else if (move == "P" || move == "p") {
      uMove = 3;
    } else {
      cout << "\n\n+---------------------------+\n| That is not a valid move. |\n+---------------------------+\n" << endl;
    }
 
    // compare the moves
    if (uMove == 1) {

      // if user attacks and enemy attacks
      if (enemyMove == 1) {
        cout << "\n++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " also attacked!\nYou -10hp\nEnemy -" << sharp << "hp\n++++++++++++++++++++++++\n" << endl;
        enemyHP = enemyHP - sharp; // sharp is sword multiplier
        userHP = userHP - enemySharp;

        // if user attacks and enemy blocks
      } else if (enemyMove == 2) {
        cout << "\n++++++++++++++++++\n" << enemy.getName(shopLvl) << " blocked.\n++++++++++++++++++\n" << endl;

        // if user attacks and enemy uses a potion
      } else if (enemyMove == 3) {

        // if word level is 0, just subtract sharp from 15
        if (swordLvl == 0) {
          cout << "\n+++++++++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " used a health potion!\nEnemy +" << 15 - sharp << "hp\n+++++++++++++++++++++++++++++++\n" << endl;

          // if sword level is 1, user deals 15 damage so nothing changes
        } else if (swordLvl == 1) {
          cout << "\n+++++++++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " used a health potion!\n+++++++++++++++++++++++++++++++\n" << endl;

          // otherwise, subtract sharp from 15
        } else {
          cout << "\n+++++++++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " used a health potion!\nEnemy -" << 15 - sharp << "hp\n+++++++++++++++++++++++++++++++\n" << endl;
        }

        // set enemy hp
        enemyHP = enemyHP + (15 - sharp);
      } 
    } else if (uMove == 2) {
    if (enemyMove == 1) {
      cout << "\n+++++++++++++++++++++++++++++++\nYou blocked " << enemy.getName(shopLvl) << "'s attack!\n+++++++++++++++++++++++++++++++\n" << endl;
    } else if (enemyMove == 2) {
      cout << "\n+++++++++++++++++++++++++++++++\nYou and " << enemy.getName(shopLvl) << " both blocked.\n+++++++++++++++++++++++++++++++\n" << endl;
    } else if (enemyMove == 3) {
      cout << "\n+++++++++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " used a health potion!\nEnemy +15hp\n+++++++++++++++++++++++++++++++\n" << endl;
      enemyHP = enemyHP + 15;
    }
  } else if (uMove == 3 && potions > 0) {
      if (enemyMove == 1) {
        cout << "\n+++++++++++++++++++++++++++++++++++++++++\nYou used a potion but " << enemy.getName(shopLvl) << " attacked!\nYou -5hp\n+++++++++++++++++++++++++++++++++++++++++\n" << endl;
        userHP = (userHP - enemySharp) + 15;
        potions--;
      } else if (enemyMove == 2) {
        cout << "\n+++++++++++++++++\n" << enemy.getName(shopLvl) << " blocked.\nYou +15hp\n+++++++++++++++++\n" << endl;
        userHP = userHP + 15;
        potions--;
      } else if (enemyMove == 3) {
        cout << "\n++++++++++++++++++++++++++++++++++++\n" << enemy.getName(shopLvl) << " also used a health potion!\nYou +15hp\nEnemy +15hp\n++++++++++++++++++++++++++++++++++++\n" << endl;
        enemyHP = enemyHP + 15;
        userHP = userHP + 15;
        potions--;
      }
    } else if (uMove == 3 && potions < 1) {
          if (enemyMove == 1) {
            cout << "\n+++++++++++++++++++++++++++++++++++++++++\nYou have no potions and " << enemy.getName(shopLvl) << " attacked!\nYou -10hp\n+++++++++++++++++++++++++++++++++++++++++\n" << endl;
            userHP = userHP - 10;
          } else if (enemyMove == 2) {
            cout << "\n++++++++++++++++++++++++\nYou have no potions and " << enemy.getName(shopLvl) << " blocked.\n+++++++++++++++++++++++++\n" << endl;
          } else if (enemyMove == 3) {
            cout << "\n++++++++++++++++++++++++++++++++++++\nYou had no potions, but " << enemy.getName(shopLvl) << " used one!\nEnemy +15hp\n++++++++++++++++++++++++++++++++++++\n" << endl;
            enemyHP = enemyHP + 15;
          }
        }
  

    // display hp
    if (userHP >= 0) {
      cout << "\nYour HP: " << userHP << endl;
    } else if (userHP < 0) {
      cout << "\nYour HP: 0" << endl;
    }

    // user health bar
    if (userHP > ((100 + armor) * (.9))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]]" << endl;
    } else if (((100 + armor) * (.8)) < userHP && userHP <= ((100 + armor) * (.9))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ]" << endl;
    } else if (((100 + armor) * (.7)) < userHP && userHP <= ((100 + armor) * (.8))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.6)) < userHP && userHP <= ((100 + armor) * (.7))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.5)) < userHP && userHP <= ((100 + armor) * (.6))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.4)) < userHP && userHP <= ((100 + armor) * (.5))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.3)) < userHP && userHP <= ((100 + armor) * (.4))) {
      cout << "[[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.2)) < userHP && userHP <= ((100 + armor) * (.3))) {
      cout << "[[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    } else if (((100 + armor) * (.1)) < userHP && userHP <= ((100 + armor) * (.2))) {
      cout << "[[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    } else if (0 < userHP && userHP <= ((100 + armor) * (.1))) {
      cout << "[[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    } else if (userHP <= 0) {
      cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    }

    cout << "\n";

    // if enemy's hp goes below zero, make sure it just says 0 noy a negative number
    if (enemyHP >= 0) {
      cout << "             " << enemy.getName(shopLvl) << "'s HP: " << enemyHP << endl;
    } else if (enemyHP < 0) {
      cout << "             " << enemy.getName(shopLvl) << "'s HP: 0" << endl;
    }

    // enemy health bar
    if (enemyHP > ((100 + (shopLvl * 20)) * (.9))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.8)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.9))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.7)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.8))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.6)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.7))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.5)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.6))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.4)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.5))) {
      cout << "[[]] [[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.3)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.4))) {
      cout << "[[]] [[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.2)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.3))) {
      cout << "[[]] [[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (((100 + (shopLvl * 20)) * (.1)) < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.2))) {
      cout << "[[]] [[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (0 < enemyHP && enemyHP <= ((100 + (shopLvl * 20)) * (.1))) {
      cout << "[[]] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    } else if (enemyHP <= 0) {
      cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]\n" << endl;
    }


    // check hp
    if (checkHP() == true) {
      alive = false;
    }
  }
}

// function to check if the user or enemy died
bool Gameplay::checkHP() {
  if (userHP < 1 || enemyHP < 1) {
    return true;
    if (enemyHP < 1) {
      enemyTracker = shopLvl;
    }
  } else
  return false;
}

// function to get the user's move
void Gameplay::getUserMove(int u) {
  uMove = u;
}

// function to set how much damage the user can take
void Gameplay::setResistance(int a)
{
  armor = a * 25;
}

// function to set how much damage the user deals
void Gameplay::setSharpness(int s) {
  sword = s * 5;
}

// function to run the entire loop of the game
void Gameplay::gameLoop() {

  // initializations
  initialize();
  initializeUHP();
  x = 0;

  // loop while the shop level is still 1-9
  while (shopLvl < 10) {

    // add un-initialized cash


    // initially check hp
    checkHP();

    // while every input is correct
    if (x == 0) {

      save(user);
      // test to find output
      // cout << "\nSAVED USER" << endl;

      string input; // variable to store input

      // output whether or not the user wants to end the game session
      cout << "\nWould you like to leave the game? Y/N" << endl;
      cout << string( 8, '\n' );
        cin >> input; // store input

      // check input
      if (input == "Y" || input == "y") {
        exit (EXIT_FAILURE); // ends program
      } else {
        cout << string( 100, '\n' ); // "new screen"
      }

      // run gameplay based on all of the user's variables
      gameplay(shopLvl, cash, swordLvl, armorLvl);

    // while all inputs are correct
    while (y == 0) {

      // if the user died
      if (userHP < 1) {

        // output
        cout << "\nThe enemy killed you!" << endl;
        cout << "\n-------------\nYou earned $0\n-------------\n" << endl;
        cout << "\nCash: $" << cash << endl;

        // new variables
        i = 1;
        userHP = 100 + armor;
        x = 1;
        y = 1;

        // if enemy died
      } else if (enemyHP < 1) {

        // if enemy died set enemyTracker to shopLvl
        if (enemyHP < 1) {
        enemyTracker = shopLvl;
        }

        // output defeat message
        cout << "\nYou defeated the enemy!" << endl;
        cout << "\n----------------------------------------------------\nWould you like to continue fighting? Y/N\n(You will enter the fight with your current hp: " << userHP << ")\n----------------------------------------------------\n" << string( 5, '\n') << endl;
          cin >> end;
          
        // if user wants to continue to fight
        if (end == "Y" || end == "y") {
          x = 0;
          i++;
          cout << string(100, '\n') << endl;
          y = 1;

          // if user does not want to continue fighting
        } else if (end == "N" || end == "n") {
          userHP = 100 + armor;
          earn = ((i - 1) * 50) + 100;
          cash = cash + earn;
          cout << string( 100, '\n' );

          if (o == 0) {
            addCash(500);
            o = 1;
            // open file based on username
            ofstream outfile;
            outfile.open(user);

            // insert variables
            outfile << shopLvl << "\n";
            outfile << swordLvl << "\n";
            outfile << armorLvl << "\n";
            outfile << cash << "\n";
            outfile << o << "\n";

            // close file
            outfile.close();
          }
          cout << "\n---------------\nYou earned $" << earn << ".\n---------------\n\nCash: $" << cash << endl;
          x = 1;
          i = 1;
          y = 1;

          // if input isn't valid
        } else {
          cout << "\nThat is not an option, check again." << endl;
          y = 0;
        }
      }
    }
    }
    
    // if the user left fighting
    if (x == 1) {
      save(user); // saves after ending shop
      loadShop(shopLvl, cash, swordLvl, armorLvl);
      x = 0;
    }

  }
}

// save new player to a file
void Gameplay::savePlayer(string username)
{
    // open file based on username
    ofstream outfile;
    username = username + ".txt";
    outfile.open(username);

    // insert variables
    outfile << shopLvl << "\n";
    outfile << swordLvl << "\n";
    outfile << armorLvl << "\n";
    outfile << cash << "\n";

    // test output for if saved correctly
    // cout << "\nsaved" << endl;

    // close file
    outfile.close();
}

// load existing user
void Gameplay::loadPlayer(string loadName)
{
  // these are temporary variables to set to real variables
  int tempShop;
  int tempArmor;
  int tempSword;
  int tempCash;
  int tempO;

    ifstream infile2; // create file
    loadName = loadName + ".txt"; // create name for the file
    string in; // create input variable
    infile2.open(loadName); // open file with created name

    cout << "\n-----------------+\n" << "  " << user << "\n-----------------+\n" << endl;

    // read level from file
    getline(infile2, in, '\n');
      stringstream ss;  
      ss << in; // input
      ss >> tempShop;
      shopLvl = tempShop; // set shoplvl
      cout << "\nYou are level " << shopLvl << "." << endl;
      ss.str(string()); // close stringstream

    // read sword level from file
    getline(infile2, in, '\n');
      stringstream ss1;
      ss1 << in; // input
      ss1 >> tempSword;
      swordLvl = tempSword; // set swordlvl
      cout << "\nSword: Level " << swordLvl << "  (" << (10 + (swordLvl * 5)) << " dps)";
      ss1.str(string()); // close

    // read armor level from file
    getline(infile2, in, '\n');
      stringstream ss2;
      ss2 << in; // input
      ss2 >> tempArmor;
      armorLvl = tempArmor; // set armorlvl
      cout << "\nArmor: Level " << armorLvl << "  (" << (100 + (armorLvl * 25)) << "hp)" << endl;
      ss2.str(string()); // close

    // read cash from file
    getline(infile2, in, '\n');
      stringstream ss3;
      ss3 << in; // input
      ss3 >> tempCash;
      cash = tempCash; // set armorlvl
      cout << "\nCash: $" << cash;
      ss3.str(string()); // close

    // read initial $500 from file
    getline(infile2, in, '\n');
      stringstream ss4;
      ss4 << in; // input
      ss4 >> tempO;
      o = tempO; // set armorlvl
      ss4.str(string()); // close

    cout << "\n------------------" << endl;

    infile2.close();

}

// set player username for easy access
void Gameplay::setPlayer(string u) {
  user = u;
}

// save player's variables after the shop is left
void Gameplay::save(string us)
{
  // open file
  ofstream outfile;
  us = user + ".txt";
  cout << endl;
  outfile.open(us);

  // insert variables
  outfile << shopLvl << "\n";
  outfile << swordLvl << "\n";
  outfile << armorLvl << "\n";
  outfile << cash << "\n";

  // test output for if saved correctly
  // cout << "\nsaved" << endl;

  // close file
  outfile.close();
}

void Gameplay::saveCash(string us) 
{
  int tempCash; // temporary cash variable

    ifstream infile2; // create file
    us = us + ".txt"; // create name for the file
    string in; // create input variable
    infile2.open(us); // open file with created name

    // read cash from file
    getline(infile2, in, '\n');
    getline(infile2, in, '\n');
    getline(infile2, in, '\n');
    stringstream ss3;
    ss3 << in; // input
    ss3 >> tempCash;
    cash = tempCash; // set cash
    ss3.str(string()); // close

  // open file
  ofstream outfile;
  us = user + ".txt";
  cout << endl;
  outfile.open(us);

  // insert variables
  outfile << cash << "\n";

  // close file
  outfile.close();
}