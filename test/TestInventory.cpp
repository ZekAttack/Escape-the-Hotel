//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Test file for Inventory class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include <sstream>
#include "../include/Inventory.h"
#include "gtest/gtest.h"
#include "../include/Exceptions.h"

TEST(TestInventory, addInvTest) {
  Inventory i;
  EXPECT_TRUE(i.addInv(0));
  EXPECT_FALSE(i.addInv(0));
  EXPECT_TRUE(i.addInv(1));
}

TEST(TestInventory, removeTest) {
  Inventory i;
  i.addInv(0);
  EXPECT_TRUE(i.remove(0));
  EXPECT_FALSE(i.remove(5));
}

TEST(TestInventory, checkInvTest) {
  Inventory i;
  i.addInv(0);
  EXPECT_TRUE(i.checkInv(0));
  EXPECT_FALSE(i.checkInv(1));
}
