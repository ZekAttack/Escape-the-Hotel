//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for NPC class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef PARSE_H
#define PARSE_H
#include "Player.h"
#include "Flag.h"
#include "Hotel.h"
#include <string>
#include <vector>
#include <iostream>

/// \brief Phase implementation is where all the inputs from the user
// are anazlyed.

/// \param[string] the user will input things as a string and getInput will
/// use it for the program.
std::vector<std::string> getInput();

/// \brief parse function is where the player and the gameState are used Based
/// off what the user will input in getInput
void parse(Player* player, Flag* gamestate,
   Hotel* htl, std::vector<std::string> wordvec);

#endif
