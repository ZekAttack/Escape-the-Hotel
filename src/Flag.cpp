//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Flag class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/Flag.h"

//// Flag for Picture
bool Flag::getFixedPicture() {
  return fixedPicture;
}
void Flag::setFixedPicture(bool setValue) {
  fixedPicture = setValue;
}

//// Flag for room
bool Flag::getPaidForRoom() {
  return paidForRoom;
}
void Flag::setPaidForRoom(bool setValue) {
  paidForRoom = setValue;
}

////Flag for door
bool Flag::getUnlockDoor() {
  return unlockDoor;
}
void Flag::setUnlockDoor(bool setValue) {
  unlockDoor = setValue;
}

//// Flag for wallet
bool Flag::getWallet() {
  return haveWallet;
}
void Flag::setWallet(bool setValue) {
  haveWallet = setValue;
}

//// Flag for knock
int Flag::getKnock() {
  return doorKnock;
}
void Flag::setKnock() {
    doorKnock++;
}
