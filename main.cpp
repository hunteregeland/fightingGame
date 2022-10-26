// cst-210 fantasy fighting game
// author: hunter egeland
// this is my own work.

#include "shop.h"
#include "gameplay.h"
#include "player.h"
#include "enemy.h"

#include <fstream>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

int main() {

  string username; // string for username
  string loadName; // temp string for name of loaded player
  string choice; // string for storing user's choice of L or N
  int v = 0; // loop variable

  Gameplay game; // object of Gameplay

  // run instructions
  game.instructions();

// choose whether to load a character or create a new one
while (v == 0) {

  // set v = 0 each iteration
  v = 0;

  // output choice
  cout << "\nStart new character or load an existing character? Enter N or L." << endl;
    cin >> choice; // sav choice as a variable

  // if new user is chosen
  if (choice == "N" || choice == "n") {
    cout << "\nEnter a username: " << endl;
      cin >> username;

    // set and save user
    game.setPlayer(username);
    game.savePlayer(username);

    v = 1; // exit loop

    // if load player is chosen
  } else if (choice == "L" || choice == "l") {

    // output to ask which user should be loaded
    cout << "\nEnter the exact name you want to load:\n " << endl;
      cin >> loadName; // set input as loadName variable
      cout << string( 100, '\n') << endl; // creates "new screen"

    // set the game to the current player's file
    game.setPlayer(loadName);
    game.loadPlayer(loadName);

    v = 1; // exit loop

    // if not N or L
  } else {
    cout << "\nThat is not an option." << endl;
    v = 0;
  }
}
  // loop through the game after user is chosen
  game.gameLoop();
}