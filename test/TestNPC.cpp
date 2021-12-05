//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Test file for NPC class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include <iostream>
#include <string>
#include "../include/NPC.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
#include "../include/Flag.h"

TEST(TestNPC, CleanerDialog) {
  bool setTrue = true;
  Flag* fl = new Flag();
  Cleaner* c = new Cleaner();

  EXPECT_EQ(c->getDialogue(), "You ask the CLEANER to move the cart.\n"
    "\"I am far too busy to help you right now,\" they say\n\""
    "I need to clean the rooms and fix"
    " that crooked PAINTING in the HALLWAY.\"\n"
    "You go to move the cart yourself, but the CLEANER slaps your hand away.\n"
    "How rude.");
  fl->setFixedPicture(setTrue);
  c->setDialogue(fl);
  EXPECT_EQ(c->getDialogue(), "\"Thank you for fixing that PAINTING for me.\"\n"
  "The CLEANER moves the cart out of the way,\n"
  "allowing access to the LOBBY.");

  delete c;
  delete fl;
}

TEST(TestNPC, ReceptionistDialog) {
  bool setTrue = true;
  Flag* fl = new Flag();
  Receptionist* r = new Receptionist();

  EXPECT_EQ(r->getDialogue(), "\"You have to checkout before"
  " you leave.\" they say.\n"
  "You don't remember checking in so this doesn't seem necessary");
  fl->setPaidForRoom(setTrue);
  r->setDialogue(fl);
  EXPECT_EQ(r->getDialogue(), "\"Thank you for staying with us!\n"
   "We hope you come again soon.\" the RECEPTIONIST says cheerfully.\n"
  "You determine that you will not be coming again soon.");

  delete r;
  delete fl;
}

TEST(TestNPC, ChefDialog) {
  bool setTrue = true;
  Flag* fl = new Flag();
  Chef* ch = new Chef();

  EXPECT_EQ(ch->getDialogue(), "You ask the CHEF if he has seen your wallet.\n"
  "\"Yeah, I've seen it!\" he shouts, chucking your wallet at you\n"
  "\"Thanks?\" you say awkwardly, picking your wallet up off the floor.\n"
  "\"What was his problem?\" you think.");
  fl->setWallet(setTrue);
  ch->setDialogue(fl);
  EXPECT_EQ(ch->getDialogue(), "\"Get out of here! I've got a "
  "RESTAURANT to run\""
  " the CHEF shouts.\nYou definitely will not be leaving a 5 star review.");

  delete ch;
  delete fl;
}
