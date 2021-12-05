//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for NPC class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/NPC.h"
#include <string>
#include "../include/Flag.h"
using std::string;

string NPC::getDialogue() {
  return dialogue;
}

void NPC::setDialogue(Flag* f) {}

Cleaner::Cleaner() {
  dialogue = "You ask the CLEANER to move the cart.\n"
    "\"I am far too busy to help you right now,\" they say\n\""
    "I need to clean the rooms and fix"
    " that crooked PAINTING in the HALLWAY.\"\n"
    "You go to move the cart yourself, but the CLEANER slaps your hand away.\n"
    "How rude.";
}

void Cleaner::setDialogue(Flag* f) {
  bool paintingStatus = f->getFixedPicture();
  if (paintingStatus == true) {
    dialogue = "\"Thank you for fixing that PAINTING for me.\"\n"
    "The CLEANER moves the cart out of the way,\n"
    "allowing access to the LOBBY.";
  }
}

Receptionist::Receptionist() {
  dialogue = "\"You have to checkout before you leave.\" they say.\n"
  "You don't remember checking in so this doesn't seem necessary";
}

void Receptionist::setDialogue(Flag* f) {
  bool roomPaid = f->getPaidForRoom();
  if (roomPaid == true) {
    dialogue = "\"Thank you for staying with us!\n"
     "We hope you come again soon.\" the RECEPTIONIST says cheerfully.\n"
    "You determine that you will not be coming again soon.";
  }
}

Chef::Chef() {
  dialogue = "You ask the CHEF if he has seen your wallet.\n"
  "\"Yeah, I've seen it!\" he shouts, chucking your wallet at you\n"
  "\"Thanks?\" you say awkwardly, picking your wallet up off the floor.\n"
  "\"What was his problem?\" you think.";
}

void Chef::setDialogue(Flag* f) {
  bool walletStatus = f->getWallet();
  if (walletStatus == true) {
    dialogue = "\"Get out of here! I've got a RESTAURANT to run\""
    " the CHEF shouts.\nYou definitely will not be leaving a 5 star review.";
  }
}
