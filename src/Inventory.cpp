//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Inventory class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/Inventory.h"
#include <vector>
using std::vector;

vector<int> Inventory::getInv() {
  return inv;
}

bool Inventory::addInv(int item) {
  if (inv.size() == 0) {
    inv.push_back(item);
    return true;
  }
  for (int i = 0; i < inv.size(); i++) {
    if (inv.at(i) == item) {
      return false;
    }
  }
  inv.push_back(item);
  return true;
}

bool Inventory::checkInv(int item) {
  for (int i = 0; i < inv.size(); i++) {
    if (inv.at(i) == item) {
      return true;
    }
  }
  return false;
}

bool Inventory::remove(int item) {
  for (int i = 0; i < inv.size(); i++) {
    if (inv.at(i) == item) {
      inv.erase(inv.begin() + i);
      return true;
    }
  }
  return false;
}
