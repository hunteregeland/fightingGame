// author: hunter egeland
// this is my own work.

#include "shop.h"
#include <iostream>
using namespace std;

// constructor
Shop::Shop()
{
}

// destructor
Shop::~Shop()
{
}

// function to initialize different variables
void Shop::initialize()
{
  // shopLvl = 0;
  // cash = 500;
  // swordLvl = 0;
  // armorLvl = 0;
  potions = 45;
}

// function to check if enemy has been killed to allow user to buy level upgrade
void Shop::killed() {

  // create enemy object
  Enemy check;

  // check each enemy based on shop level
  if (check.getName(shopLvl) == "Ryan Iskandar" && enemyTracker == 0) {
    hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Sam Tipton" && enemyTracker == 1) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Patrick Faloona" && enemyTracker == 2) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Niko Zeiner" && enemyTracker == 3) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Hunter Egeland" && enemyTracker == 4) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Brendan Quinn" && enemyTracker == 5) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Phoenix Rodas" && enemyTracker == 6) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Emmanuel Dizon" && enemyTracker == 7) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Aidan Koanui" && enemyTracker == 8) {
      hasBeenKilled = true;
  } else if (check.getName(shopLvl) == "Jordan Kerkvliet" && enemyTracker == 9) {
      hasBeenKilled = true;
  } 
} 

// function to set the cash value
void Shop::setCash(int c)
{
  cash = c;
}

// function to get the cash value
void Shop::getCash()
{
  cout << "\nYou have $" << cash << ".\n" << endl;
}

// function to add cash to current cash value
void Shop::addCash(int add)
{
  cash = cash + add;
}

// function to add a potion to the current value
void Shop::addPotion()
{
  potions++;
}

// function to remove a potion from the current value
void Shop::removePotion()
{
  potions--;
}

// function to display shop, sword, armor levels and amount of potions
void Shop::display()
{
  cout << endl;
  cout << "\nYou are level " << shopLvl << "." << endl;
  cout << "\nCash: $" << cash;
  cout << "\nSword: Level " << swordLvl << "  (" << (10 + (swordLvl * 5)) << " dps)";
  cout << "\nArmor: Level " << armorLvl << "  (" << (100 + (armorLvl * 25)) << "hp)" << endl;
  cout << "\nYou have " << potions << " Health Potions." << endl;
  cout << "\n------------------" << endl;
  cout << endl;
}

// function to load the shop
void Shop::loadShop(int lvl, int c, int sword, int armor) 
{

  // set local variables to variables in shop.h
  lvl = shopLvl;
  c = cash;
  sword = swordLvl;
  armor = armorLvl;

// starting shop
  while (shopLvl == 0) {

    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| (↑) Level 1 Upgrade Package: $500 |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Level 1 Upgrade: U      |" << endl;
 
    cout << "+-----------------------------------+" << endl;
    cout << endl;

  // ask user if they want to leave the shop or not
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 13, '\n' );
      cin >> decision;

      // if leave is chosen
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;

        // if buy is chosen
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );

        // output asking what the user wants to buy
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;

        // output shop UI
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| (↑) Level 1 Upgrade Package: $500 |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Level 1 Upgrade: U      |" << endl;
    
        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 15, '\n' );

        // if B or L is not entered
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

    // set input to variable
    cin >> buy;
  
    // if level upgrade is chosen
    if ((buy == "U" || buy == "u")) {

      // run killed function
      killed();

      // use hasBeenKilled to check if enemy has been killed
      if (hasBeenKilled == true) {
        // if not enough cash
        if (cash < 500) {
          cout << "\nYou don't have enough cash to buy that!" << endl;

        // if enemy has been killed and user has enough cash
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 1 ]" << endl;
          shopLvl++;
          cash = cash - 500;
          cout << "\nCash: $" << cash << endl;
          }
        // if the level enemy hasn't been killed yet
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
      // if U is not entered
    } else {
      cout << "\nThat is not an available item to buy, check again." << endl;
    }
  } 

// ALL SHOPS ARE THE SAME WITH SLIGHTLY DIFFERENT NUMBERS AND PRICES, SAME UI JUST LEVELS UP EACH TIME THE SHOPLVL IS INCREASED.

// level 1 shop
  while (shopLvl == 1) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 1 Sword  : $50         |" << endl;
    cout << "| (ᗜ) Level 1 Armor  : $100         |" << endl;
    cout << "| (↑) Level 2 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 1 Sword: S        |" << endl;
    cout << "|       Buy Level 1 Armor: A        |" << endl;
    cout << "|      Buy Level 2 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

  // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 1 Sword  : $50         |" << endl;
        cout << "| (ᗜ) Level 1 Armor  : $100         |" << endl;
        cout << "| (↑) Level 2 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 1 Sword: S        |" << endl;
        cout << "|       Buy Level 1 Armor: A        |" << endl;
        cout << "|      Buy Level 2 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 2 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
          }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 1 sword
    if (buy == "S" || buy == "s") {
      if (cash < 50 || swordLvl == 1) {
        if (cash < 50) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 1) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 1 Sword!" << endl;
      swordLvl++;
      cash = cash - 50;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 1 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 1) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 1) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 1 Armor!" << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "You don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 2 shop
  while (shopLvl == 2) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 2 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 2 Armor  : $100         |" << endl;
    cout << "| (↑) Level 3 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 2 Sword: S        |" << endl;
    cout << "|       Buy Level 2 Armor: A        |" << endl;
    cout << "|      Buy Level 3 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 2 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 2 Armor  : $100         |" << endl;
        cout << "| (↑) Level 3 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 2 Sword: S        |" << endl;
        cout << "|       Buy Level 2 Armor: A        |" << endl;
        cout << "|      Buy Level 3 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 3 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 2 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 2) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 2) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 2 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 2 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 2) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 2) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 2 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 3 shop
  while (shopLvl == 3) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 3 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 3 Armor  : $100         |" << endl;
    cout << "| (↑) Level 4 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 3 Sword: S        |" << endl;
    cout << "|       Buy Level 3 Armor: A        |" << endl;
    cout << "|      Buy Level 4 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 3 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 3 Armor  : $100         |" << endl;
        cout << "| (↑) Level 4 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 3 Sword: S        |" << endl;
        cout << "|       Buy Level 3 Armor: A        |" << endl;
        cout << "|      Buy Level 4 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 4 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 2 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 3) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 3) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 3 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 2 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 3) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 3) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 3 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 4 shop
  while (shopLvl == 4) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 4 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 4 Armor  : $100         |" << endl;
    cout << "| (↑) Level 5 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 4 Sword: S        |" << endl;
    cout << "|       Buy Level 4 Armor: A        |" << endl;
    cout << "|      Buy Level 5 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 4 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 4 Armor  : $100         |" << endl;
        cout << "| (↑) Level 5 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 4 Sword: S        |" << endl;
        cout << "|       Buy Level 4 Armor: A        |" << endl;
        cout << "|      Buy Level 5 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 5 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 2 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 4) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 4) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 4 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 2 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 4) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 4) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 4 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 5 shop
  while (shopLvl == 5) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 5 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 5 Armor  : $100         |" << endl;
    cout << "| (↑) Level 6 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 5 Sword: S        |" << endl;
    cout << "|       Buy Level 5 Armor: A        |" << endl;
    cout << "|      Buy Level 6 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 5 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 5 Armor  : $100         |" << endl;
        cout << "| (↑) Level 6 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 5 Sword: S        |" << endl;
        cout << "|       Buy Level 5 Armor: A        |" << endl;
        cout << "|      Buy Level 6 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 6 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 5 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 5) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 5) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 5 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 5 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 5) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 5) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 5 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 6 shop
  while (shopLvl == 6) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 6 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 6 Armor  : $100         |" << endl;
    cout << "| (↑) Level 7 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 6 Sword: S        |" << endl;
    cout << "|       Buy Level 6 Armor: A        |" << endl;
    cout << "|      Buy Level 7 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 6 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 6 Armor  : $100         |" << endl;
        cout << "| (↑) Level 7 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 6 Sword: S        |" << endl;
        cout << "|       Buy Level 6 Armor: A        |" << endl;
        cout << "|      Buy Level 7 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 7 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 6 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 6) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 6) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 6 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 6 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 6) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 6) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 6 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 7 shop
  while (shopLvl == 7) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 7 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 7 Armor  : $100         |" << endl;
    cout << "| (↑) Level 8 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 7 Sword: S        |" << endl;
    cout << "|       Buy Level 7 Armor: A        |" << endl;
    cout << "|      Buy Level 8 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 7 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 7 Armor  : $100         |" << endl;
        cout << "| (↑) Level 8 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 7 Sword: S        |" << endl;
        cout << "|       Buy Level 7 Armor: A        |" << endl;
        cout << "|      Buy Level 8 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 8 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 7 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 7) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 7) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 7 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 7 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 7) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 7) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 7 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 8 shop
  while (shopLvl == 8) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 8 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 8 Armor  : $100         |" << endl;
    cout << "| (↑) Level 9 Upgrade  : $250       |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 8 Sword: S        |" << endl;
    cout << "|       Buy Level 8 Armor: A        |" << endl;
    cout << "|      Buy Level 9 Upgrade: U       |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 8 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 8 Armor  : $100         |" << endl;
        cout << "| (↑) Level 9 Upgrade  : $250       |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 8 Sword: S        |" << endl;
        cout << "|       Buy Level 8 Armor: A        |" << endl;
        cout << "|      Buy Level 9 Upgrade: U       |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "U" || buy == "u" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // level upgrade
    if (buy == "U" || buy == "u") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nLevel Up!  [ Level 9 ]" << endl;
          shopLvl++;
          cash = cash - 250;
          cout << "\nCash: $" << cash << endl;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 8 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 8) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 8) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 8 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 8 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 8) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 8) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 8 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}

// level 9 shop
  while (shopLvl == 9) {
    cout << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "|               SHOP                |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << "| Available Items:                  |" << endl;
    cout << "| (+) Health Potion  : $5           |" << endl;
    cout << "| (乂) Level 9 Sword  : $100        |" << endl;
    cout << "| (ᗜ) Level 9 Armor  : $100         |" << endl;
    cout << "| (↑) End Game  : $250              |" << endl;

    cout << "+-----------------------------------+" << endl;

    cout << "|       Buy Health Potion: P        |" << endl;
    cout << "|       Buy Level 9 Sword: S        |" << endl;
    cout << "|       Buy Level 9 Armor: A        |" << endl;
    cout << "|            End Game: E            |" << endl;

    cout << "+-----------------------------------+" << endl;
    cout << endl;

    // ask user if they want to leave the shop
    cout << "Want to buy something or leave the shop?\nEnter B or L." << endl;
    cout << string( 8, '\n' );
      cin >> decision;
      if (decision == "L" || decision == "l") {
        cout << string( 100, '\n' );
        cout << "\n------------------\nYou left the shop.\n------------------" << endl;
        display();
        break;
      } else if (decision == "B" || decision == "b") {
        cout << string( 100, '\n' );
        cout << "\n-------------------\nChoose what to buy!\n-------------------\n\nCash: $" << cash << endl;
        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|               SHOP                |" << endl;
        cout << "+-----------------------------------+" << endl;

        cout << "| Available Items:                  |" << endl;
        cout << "| (+) Health Potion  : $5           |" << endl;
        cout << "| (乂) Level 9 Sword  : $100        |" << endl;
        cout << "| (ᗜ) Level 9 Armor  : $100         |" << endl;
        cout << "| (↑) End Game  : $250              |" << endl;

        cout << "+-----------------------------------+" << endl;

        cout << "|       Buy Health Potion: P        |" << endl;
        cout << "|       Buy Level 9 Sword: S        |" << endl;
        cout << "|       Buy Level 9 Armor: A        |" << endl;
        cout << "|            End Game: E            |" << endl;

        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << string( 10, '\n' );
      } else {
        cout << "\n----------------------\nThat is not an option.\n----------------------" << endl;
        loadShop(shopLvl, cash, swordLvl, armorLvl);
        }

  // set input to variable
    cin >> buy;

  if (buy == "E" || buy == "e" || buy == "P" || buy == "p" || buy == "S" || buy == "s" || buy == "A" || buy == "a") {

    // end game
    if (buy == "E" || buy == "e") {
      killed();
      if (hasBeenKilled == true) {
        if (cash < 250) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        } else {
          cout << string( 100, '\n' );
          cout << "\nYou beat the game, congratulations!" << endl;
          cout << string( 15, '\n' );
          shopLvl++;
          cash = cash - 250;
        }
      } else {
        cout << "\nYou have to kill the Level " << shopLvl << " boss before you can purchase this Level Upgrade." << endl;
      }
    }

    // level 9 sword
    if (buy == "S" || buy == "s") {
      if (cash < 100 || swordLvl == 9) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (swordLvl == 2) {
          cout << "\nYou already own this sword." << endl;
        }
      } else {
      cout << "\nYou acquired a Level 9 Sword!" << endl;
      swordLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // level 9 armor
    if (buy == "A" || buy == "a") {
      if (cash < 100 || armorLvl == 9) {
        if (cash < 100) {
          cout << "\nYou don't have enough cash to buy that!" << endl;
        }
        if (armorLvl == 2) {
          cout << "\nYou already own this armor." << endl;
        }
      } else {
      cout << "\nYou acquired Level 9 Armor!" << armorLvl << endl;
      armorLvl++;
      cash = cash - 100;
      cout << "\nCash: $" << cash << endl;
      } 
    }

    // health potion
    if (buy == "P" || buy == "p") {
      if (cash < 5) {
        cout << "\nYou don't have enough cash to buy that!" << endl;
      } else {
      addPotion();
      cout << "\nYou acquired a Health Potion! You now have " << potions << " potions." << endl;
      cash = cash - 5;
      cout << "\nCash: $" << cash << endl;
      } 
    }
  } else {
    cout << "\nThat is not an available item to buy, check again." << endl;
  }
}
}
