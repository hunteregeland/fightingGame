// author: hunter egeland
// this is my own work.

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "shop.h"
#include "player.h"

#include <string>
#include <iostream>

using namespace std;

class Gameplay: public Shop
{
  private:

  double resistance; // double for how much damage the user can take
  int playerMove; // int for storing playerMove inside gameplay
  bool alive; // bool for if the player is alive or dead
  string end; // string for whether or not to end the game
  
  // ints for loop management
  int i = 1;
  int j = 0;
  int x = 0;
  int y = 0;
  int z = 0;

  int savedCash;

  public:

  string user; // username storage
  
  int uMove = 0; // int for storing the user's move
  int eMove = 0; // int for storing the enemy's move
  int earn = 0; // int for how much cash is earned after a fight
  string name; // string for name of user

  Gameplay();
  ~Gameplay();

  void instructions();
  void initializeUHP();
  void initializeEHP();
  void gameplay(int, int, int, int);
  void fighting();
  bool checkHP();
  void displayHP();

  void getUserMove(int);
  void setResistance(int);
  void setSharpness(int);

  void gameLoop();

  void savePlayer(string);
  void loadPlayer(string);

  void setPlayer(string);
  void save(string);
  void saveCash(string);

};
#endif