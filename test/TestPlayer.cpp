//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Test file for Player class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************
// #include <sstream>
#include <iostream>
#include "../include/Player.h"
#include "../include/Room.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestPlayer, moveTest) {
  Player* p = new Player();
  Room* hr = new HotelRoom();
  Room* hb = new HotelBathroom();
  p->setPlayerRoom(hr);
  hr->setRoomNorth(hb);
  p->roomMove('n');
  ASSERT_EQ(p->getCurRoom(), hb);
  hb->setRoomEast(hr);
  p->roomMove('e');
  ASSERT_EQ(p->getCurRoom(), hr);
  hr->setRoomSouth(hb);
  p->roomMove('s');
  ASSERT_EQ(p->getCurRoom(), hb);
  hb->setRoomWest(hr);
  p->roomMove('w');
  ASSERT_EQ(p->getCurRoom(), hr);
  hr->setRoomNorth(nullptr);
  hr->setRoomEast(nullptr);
  hr->setRoomSouth(nullptr);
  hr->setRoomWest(nullptr);
  p->roomMove('n');
  ASSERT_EQ(p->getCurRoom(), hr);
  p->roomMove('e');
  ASSERT_EQ(p->getCurRoom(), hr);
  p->roomMove('s');
  ASSERT_EQ(p->getCurRoom(), hr);
  p->roomMove('w');
  ASSERT_EQ(p->getCurRoom(), hr);
  EXPECT_THROW(p->roomMove('t'), invalid_parameter);
  delete p;
  delete hr;
  delete hb;
}
TEST(TestPlayer, takeTest) {
  Player* p = new Player();
  Room* hr = new HotelRoom();
  p->setPlayerRoom(hr);
  hr->addRoomInv(1);
  EXPECT_EQ(p->checkInv(1), false);
  p->take(1);
  EXPECT_EQ(p->checkInv(1), true);
  EXPECT_EQ(hr->checkRoomInv(1), false);
  delete p;
  delete hr;
}
TEST(TestPlayer, checkAddRemoveInvTest) {
  Player* p = new Player();
  EXPECT_EQ(p->checkInv(1), false);
  p->addPlayerInv(1);
  EXPECT_EQ(p->addPlayerInv(1), false);
  EXPECT_EQ(p->checkInv(1), true);
  p->removePlayerInv(1);
  EXPECT_EQ(p->checkInv(1), false);
  EXPECT_EQ(p->removePlayerInv(36), false);
  delete p;
}
TEST(TestPlayer, getSetCurRoomTest) {
  Player* p = new Player();
  Room* hr = new HotelRoom();
  Room* hb = new HotelBathroom();
  EXPECT_EQ(p->getCurRoom(), nullptr);
  p->setPlayerRoom(hr);
  EXPECT_EQ(p->getCurRoom(), hr);
  p->setPlayerRoom(hb);
  EXPECT_EQ(p->getCurRoom(), hb);
  delete p;
  delete hr;
  delete hb;
}

TEST(TestPlayer, helpTest) {
  Player* p = new Player();
  EXPECT_NO_THROW(p->help());
  delete p;
}

TEST(TestPlayer, invTest) {
  Player* p = new Player();
  EXPECT_NO_THROW(p->inv());
  p->addPlayerInv(1);
  p->addPlayerInv(2);
  p->addPlayerInv(3);
  EXPECT_NO_THROW(p->inv());
  delete p;
}
