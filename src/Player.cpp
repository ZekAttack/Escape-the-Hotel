//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Player class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "Player.h"
#include "Flag.h"
#include "Inventory.h"
#include "Room.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

Room *Player::roomMove(char direction) {
  switch (direction) {
    case 'n':
    if (this->currentRoom->getRoomNorth() != nullptr) {
      this->currentRoom = this->currentRoom->getRoomNorth();
      std::cout << this->getCurRoom()->getDescription()
      << std::endl;
    } else {std::cout << "You can't go that way" << std::endl;}
    break;
    case 'w':
    if (this->currentRoom->getRoomWest() != nullptr) {
      this->currentRoom = this->currentRoom->getRoomWest();
      std::cout << this->getCurRoom()->getDescription()
      << std::endl;
    } else {std::cout << "You can't go that way" << std::endl;}
    break;
    case 's':
    if (this->currentRoom->getRoomSouth() != nullptr) {
      this->currentRoom = this->currentRoom->getRoomSouth();
      std::cout << this->getCurRoom()->getDescription()
      << std::endl;
    } else {std::cout << "You can't go that way" << std::endl;}
    break;
    case 'e':
    if (this->currentRoom->getRoomEast() != nullptr) {
      this->currentRoom = this->currentRoom->getRoomEast();
      std::cout << this->getCurRoom()->getDescription()
      << std::endl;
    } else {std::cout << "You can't go that way" << std::endl;}
    break;
    default:
    throw invalid_parameter("Received non cardinal direction in move function");
    break;
  }
    return this->currentRoom;
}

void Player::help() {
  std::cout << std::endl << "Possible Commands" << std::endl;
  std::cout << "MOVE - used to move to new area" << std::endl;
  std::cout << "INTERACT - interacts with an item or person in the game";
  std::cout << std::endl;
  std::cout << "HELP - brings up this menu" << std::endl;
  std::cout << "TAKE - takes an item from the environment if possible";
  std::cout << std::endl;
  std::cout << "INVENTORY - displays item's currently in your inventory";
  std::cout << std::endl << std::endl;
}

void Player::take(int item) {
  this->addPlayerInv(item);
  currentRoom->removeRoomInv(item);
}

bool Player::checkInv(int item) {
  bool result;
  result = this->playerInventory.checkInv(item);
  return result;
}

bool Player::addPlayerInv(int item) {
  if (playerInventory.addInv(item)) {
    return true;
  } else {
    return false;
  }
}

bool Player::removePlayerInv(int item) {
  if (playerInventory.remove(item)) {
    return true;
  } else {
    return false;
  }
}

void Player::inv() {
  if (playerInventory.getInv().size() == 0) {
    std::cout << "Your inventory is empty.\n";
  } else {
    for (int i = 0; i < playerInventory.getInv().size(); i++) {
      std::cout << "[" << i+1 << "] ";
      int item = playerInventory.getInv().at(i);
      switch (item) {
        case 1:
          std::cout << "Key" << std::endl;
          continue;
        case 7:
          std::cout << "Wallet" << std::endl;
          continue;
        }
    }
  }
}

Room *Player::getCurRoom() {
  return currentRoom;
}

void Player::setPlayerRoom(Room* place) {
  currentRoom = place;
}
