//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for NPC class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef NPC_H
#define NPC_H
#include <string>
#include "../include/Flag.h"
using std::string;

/// \brief Implementation of characters for the player to interact with.

/// \class NPC NPC.h "../include/NPC.h"
class NPC {
 public:
  /// \brief Returns the dialogue for an NPC.
  string getDialogue();
  /// \brief virtual function for setDialogue.
  virtual void setDialogue(Flag* f);

 protected:
  string dialogue;
};

/// \class Cleaner NPC.h "../include/NPC.h"
class Cleaner : public NPC {
 public:
  /// \brief Default constructor
  Cleaner();

  /// \brief Changes the cleaner's dialogue.
  /// \param[in] f Object to pass in to the see state of the game.
  void setDialogue(Flag* f);
};

/// \class Receptionist NPC.h "../include/NPC.h"
class Receptionist : public NPC {
 public:
  /// \brief Default constructor
  Receptionist();

  /// \brief Changes the receptionist's dialogue.
  /// \param[in] f Object to pass in to the see state of the game.
  void setDialogue(Flag* f);
};

/// \class Chef NPC.h "../include/NPC.h"
class Chef : public NPC {
 public:
  /// \brief Default constructor
  Chef();

  /// \brief Changes the chef's dialogue.
  /// \param[in] f Object to pass in to the see state of the game.
  void setDialogue(Flag* f);
};


#endif
