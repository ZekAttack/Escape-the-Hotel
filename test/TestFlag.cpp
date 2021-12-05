// //***********************************************************************
// // CS2720A - Fall 2020 - Text Based Adventure Game
// // Instructor: Dr. John Anvik
// // Escape The Hotel - Team Infinity
// //
// // Test file for Flag class
// // Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// // Date: Nov 1, 2020
// //***********************************************************************

#include <sstream>
#include "../include/Flag.h"
#include "gtest/gtest.h"
#include "../include/Exceptions.h"

TEST(TestFlag, getFixedPictureTest) {
  Flag f;
  EXPECT_FALSE(f.getFixedPicture());
}

TEST(TestFlag, setFixedPictureTest) {
  bool setValue = true;
  Flag f;
  f.setFixedPicture(setValue);
  EXPECT_TRUE(f.getFixedPicture());
}

TEST(TestFlag, getPaidForRoomTest) {
  Flag f;
  EXPECT_FALSE(f.getPaidForRoom());
}

TEST(TestFlag, setPaidForRoomTest) {
  bool setValue = true;
  Flag f;
  f.setPaidForRoom(setValue);
  EXPECT_TRUE(f.getPaidForRoom());
}

TEST(TestFlag, getUnlockDoorTest) {
  Flag f;
  EXPECT_FALSE(f.getUnlockDoor());
}

TEST(TestFlag, setUnlockDoorTest) {
  bool setValue = true;
  Flag f;
  f.setUnlockDoor(setValue);
  EXPECT_TRUE(f.getUnlockDoor());
}

TEST(TestFlag, getWallet) {
  Flag f;
  EXPECT_FALSE(f.getWallet());
}

TEST(TestFlag, setWallet) {
  bool setValue = true;
  Flag f;
  f.setWallet(setValue);
  EXPECT_TRUE(f.getWallet());
}

TEST(TestFlag, getKnockTest) {
  Flag f;
  EXPECT_EQ(f.getKnock(), 0);
}

TEST(TestFlag, setKnockTest) {
  Flag f;
  f.setKnock();
  EXPECT_EQ(f.getKnock(), 1);
}
