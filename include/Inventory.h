//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for Inventory class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
using std::vector;

/// \brief Contains all information related to the inventorys.
/// Allows for checking, adding and removing of items.

/// \class Inventory Inventory.h "../include/Inventory.h"
class Inventory {
 public:
  /// \brief Returns the inventory of the room or player.
    vector<int> getInv();

  /// \brief Adds an item to the inventory of the room or player.
  /// \param[in] item The item to be added
    bool addInv(int item);

  /// \brief Removes an item to the inventory of the room or player.
  /// Returns true if removal is successful and false otherwise.
  /// \param[in] item The item to be removed
    bool remove(int item);

  /// \brief Checks to see if an item is in the
  /// inventory of the room or player.
  /// Returns true if the item is present or false otherwise.
  /// \param[in] item The item to be checked.
    bool checkInv(int item);

 private:
    vector<int> inv;
};

#endif
