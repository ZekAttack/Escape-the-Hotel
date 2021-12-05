//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Test file for Room class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//*********************************************************************
#include <sstream>
#include "../include/Room.h"
#include "../include/Inventory.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestRoom, setRoomNorthTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();
  HotelBalcony* hbl = new HotelBalcony();

//  EXPECT_EQ(hr->getRoomNorth(), hbr);

  delete hr;
  delete hbr;
  delete hbl;
}

TEST(TestRoom, getRoomNorthTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

//  EXPECT_EQ(hr->getRoomNorth(), nullptr);
//   EXPECT_EQ(hr->getRoomNorth(), hbr);

  delete hr;
  delete hbr;
}

TEST(TestRoom, setRoomEastTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();
  HotelBalcony* hbl = new HotelBalcony();

//   EXPECT_EQ(hr->getRoomEast(), hbr);

  delete hr;
  delete hbr;
  delete hbl;
}

TEST(TestRoom, getRoomEastTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

//   EXPECT_EQ(hr->getRoomEast(), nullptr);
//   EXPECT_EQ(hr->getRoomEast(), hbr);

  delete hr;
  delete hbr;
}

TEST(TestRoom, setRoomSouthTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();
  HotelBalcony* hbl = new HotelBalcony();

//   EXPECT_EQ(hr->getRoomSouth(), hbr);

  delete hr;
  delete hbr;
  delete hbl;
}

TEST(TestRoom, getRoomSouthTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

//   EXPECT_EQ(hr->getRoomSouth(), nullptr);
//   EXPECT_EQ(hr->getRoomSouth(), hbr);

  delete hr;
  delete hbr;
}

TEST(TestRoom, setRoomWestTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();
  HotelBalcony* hbl = new HotelBalcony();

//   EXPECT_EQ(hr->getRoomWest(), hbr);

  delete hr;
  delete hbr;
  delete hbl;
}

TEST(TestRoom, getRoomWestTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

//   EXPECT_EQ(hr->getRoomWest(), nullptr);
//   EXPECT_EQ(hr->getRoomWest(), hbr);

  delete hr;
  delete hbr;
}

TEST(TestRoom, getRoomInvTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

  EXPECT_TRUE(hr->addRoomInv(0));
  EXPECT_TRUE(hbr->addRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hr->removeRoomInv(0));
  EXPECT_NE(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hbr->removeRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());

  delete hr;
  delete hbr;
}

TEST(TestRoom, addRoomInvTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

  EXPECT_TRUE(hr->addRoomInv(0));
  EXPECT_TRUE(hbr->addRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hr->removeRoomInv(0));
  EXPECT_NE(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hbr->removeRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());

  delete hr;
  delete hbr;
}

TEST(TestRoom, removeRoomInvTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

  EXPECT_TRUE(hr->addRoomInv(0));
  EXPECT_TRUE(hbr->addRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hr->removeRoomInv(0));
  EXPECT_NE(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());
  EXPECT_TRUE(hbr->removeRoomInv(0));
  EXPECT_EQ(hr->getRoomInv().getInv(), hbr->getRoomInv().getInv());

  delete hr;
  delete hbr;
}

TEST(TestRoom, getNameTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

  EXPECT_EQ(hr->getName(), "HotelRoom");
  EXPECT_EQ(hbr->getName(), "HotelBathroom");
  hr->setName("Potato");
  hbr->setName("Potato");
  EXPECT_EQ(hr->getName(), hbr->getName());
  hbr->setName("Tomato");
  EXPECT_NE(hr->getName(), hbr->getName());

  delete hr;
  delete hbr;
}

TEST(TestRoom, setNameTest) {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbr = new HotelBathroom();

  EXPECT_EQ(hr->getName(), "HotelRoom");
  EXPECT_EQ(hbr->getName(), "HotelBathroom");
  hr->setName("Potato");
  hbr->setName("Potato");
  EXPECT_EQ(hr->getName(), hbr->getName());
  hbr->setName("Tomato");
  EXPECT_NE(hr->getName(), hbr->getName());

  delete hr;
  delete hbr;
}

TEST(TestRoom, getDescriptionTest) {
  HallwayElevator* he = new HallwayElevator();

  EXPECT_EQ(he->getDescription(),
  "You pry the elevator doors open and step inside.\n"
  "You see one large BUTTON labelled \"Lobby\".");

  delete he;
}
