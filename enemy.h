// author: hunter egeland
// this is my own work.

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>

using namespace std;

class Enemy
{
  private:

  public:

  int enemyHP = 0; // int for enemy hp
  int enemySharp = 0; // int for how much dps the enemy does
  int enemyMove = 0; // int for randomized enemy move

  string name[10]; // array for enemy names

  Enemy();
  ~Enemy();

  void getEnemyMove();
  void setEnemyHP(int);
  string getName(int);
  
};
#endif