// author: hunter egeland
// this is my own work.

#include "enemy.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

// constructor
Enemy::Enemy() 
{
}

// destructor
Enemy::~Enemy()
{
}

// function to get a random enemy move (a,b,p)
void Enemy::getEnemyMove() {
  // generate random number
  srand (time(NULL));
  enemyMove = rand() % 3 + 1;
  // cout << enemyMove; // test
}

// function to set enemy hp
void Enemy::setEnemyHP(int hp) {
  enemyHP = hp;
}

// function to get name of enemy based off of level
string Enemy::getName(int i) {
  name[0] = "Ryan Iskandar";
  name[1] = "Sam Tipton";
  name[2] = "Patrick Faloona";
  name[3] = "Niko Zeiner";
  name[4] = "Hunter Egeland";
  name[5] = "Brendan Quinn";
  name[6] = "Phoenix Rodas";
  name[7] = "Emmanuel Dizon";
  name[8] = "Aidan Koanui";
  name[9] = "Jordan Kerkvliet";

  return name[i];
}
