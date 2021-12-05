//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for Player class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef PLAYER_H
#define PLAYER_H
#include "Inventory.h"
#include "Room.h"
#include "Flag.h"
#include <iostream>
#include <string>

/// \brief \class Player implementation of all the abilities of the player
class Player {
 public:
  /// \brief Moves the player in a given direction.
  /// Returns the room the player is in after the move.
  /// \param[char]
  Room *roomMove(char direction);

  /// \brief Outputs the possible actions at any given time
  void help();

  /// \brief Adds a found item to the player's inventory
  /// Return true if the item is a valid inventory item,
  /// returns false otherwise
  /// \param[int]
  void take(int item);

  /// \brief Outputs the players current inventory
  void inv();

  /// \brief checks for the inventory
  /// Returns true if the item passed in is in the players inventory
  /// \param[int]
  bool checkInv(int item);

  /// \brief get the current room
  /// Returns pointer to current room
  Room *getCurRoom();

  /// \brief Adds an item to the players' inventory
  /// Returns true if successful, returns false otherwise
  /// \param[int]
  bool addPlayerInv(int item);

  /// \brief Removes an item from the players' Inventory
  /// Returns true if successful, returns false otherwise
  /// \param[int] item
  bool removePlayerInv(int item);

  /// \brief Sets the players current room
  /// \param[Room*] place
  void setPlayerRoom(Room* place);

 private:
  Room *currentRoom;
  Inventory playerInventory;
};

#endif
