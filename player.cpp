// author: hunter egeland
// this is my own work.

#include "player.h"
#include <iostream>
using namespace std;

// constructor
Player::Player()
{
}

// destructor
Player::~Player() 
{
}

// function to set player hp
void Player::setPlayerHP(int hp)
{
  userHP = hp;
}

