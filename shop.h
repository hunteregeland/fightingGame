// author: hunter egeland
// this is my own work.

#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include "enemy.h"
#include <string>
#include <iostream>
using namespace std;

class Shop: public Player, public Enemy
{
  private:

  string buy; // string for storing whether or not the user wants to buy something
  string decision; // string for storing what the user wants to buy

  public:

  Shop();
  ~Shop();

  string user; // string for storing the user

  int shopLvl = 0; // int for shop level
  int cash = 0; // int for cash
  int potions = 0; // int for amount of potions
  int o = 0;

  int enemyTracker = 99999999; // int tracking which enemy and its hp
  bool hasBeenKilled = false; // bool for whether or not the enemy at each level has been killed, used to determine whether or not a user can but a level upgrade

  void initialize();
  void loadShop(int, int, int, int);

  void setCash(int);
  void getCash();
  void setInitals();
  void addCash(int);

  void killed();

  void addPotion();
  void removePotion();

  void display();
  
};
#endif
