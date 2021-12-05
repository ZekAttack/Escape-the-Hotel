//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Test file for Hotel class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************
#include <vector>
#include <string>
#include "../include/Hotel.h"
#include "../include/Room.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(testhotel, constructorTest) {
  Hotel* h = new Hotel();
  EXPECT_EQ(h->getHotel().size(), 14);
  EXPECT_EQ(h->findRoom("HotelRoom")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("HotelRoom")->getRoomEast(), nullptr);
  EXPECT_EQ(h->findRoom("HotelRoom")->getRoomSouth(),
  h->findRoom("HotelBalcony"));
  EXPECT_EQ(h->findRoom("HotelRoom")->getRoomWest(),
  h->findRoom("HotelBathroom"));

  EXPECT_EQ(h->findRoom("HotelBathroom")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("HotelBathroom")->getRoomEast(),
  h->findRoom("HotelRoom"));
  EXPECT_EQ(h->findRoom("HotelBathroom")->getRoomSouth(), nullptr);
  EXPECT_EQ(h->findRoom("HotelBathroom")->getRoomWest(), nullptr);

  EXPECT_EQ(h->findRoom("HotelBalcony")->getRoomNorth(),
  h->findRoom("HotelRoom"));
  EXPECT_EQ(h->findRoom("HotelBalcony")->getRoomEast(), nullptr);
  EXPECT_EQ(h->findRoom("HotelBalcony")->getRoomSouth(),
  h->findRoom("FailureBalcony"));
  EXPECT_EQ(h->findRoom("HotelBalcony")->getRoomWest(), nullptr);

  EXPECT_EQ(h->findRoom("Hallway")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("Hallway")->getRoomEast(),
  h->findRoom("HallwayElevator"));
  EXPECT_EQ(h->findRoom("Hallway")->getRoomSouth(),
  h->findRoom("HotelRoom"));
  EXPECT_EQ(h->findRoom("Hallway")->getRoomWest(),
  h->findRoom("HallwayStairwell"));

  EXPECT_EQ(h->findRoom("HallwayStairwell")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("HallwayStairwell")->getRoomEast(),
  h->findRoom("Hallway"));
  EXPECT_EQ(h->findRoom("HallwayStairwell")->getRoomSouth(), nullptr);
  EXPECT_EQ(h->findRoom("HallwayStairwell")->getRoomWest(), nullptr);

  EXPECT_EQ(h->findRoom("HallwayElevator")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("HallwayElevator")->getRoomEast(), nullptr);
  EXPECT_EQ(h->findRoom("HallwayElevator")->getRoomSouth(), nullptr);
  EXPECT_EQ(h->findRoom("HallwayElevator")->getRoomWest(),
  h->findRoom("Hallway"));

  EXPECT_EQ(h->findRoom("Lobby")->getRoomNorth(),
  h->findRoom("LobbyReception"));
  EXPECT_EQ(h->findRoom("Lobby")->getRoomEast(),
  h->findRoom("HallwayStairwell"));
  EXPECT_EQ(h->findRoom("Lobby")->getRoomSouth(),
  h->findRoom("FailureArrested"));
  EXPECT_EQ(h->findRoom("Lobby")->getRoomWest(),
  h->findRoom("LobbyRestaurant"));

  EXPECT_EQ(h->findRoom("LobbyReception")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("LobbyReception")->getRoomEast(), nullptr);
  EXPECT_EQ(h->findRoom("LobbyReception")->getRoomSouth(),
  h->findRoom("Lobby"));
  EXPECT_EQ(h->findRoom("LobbyReception")->getRoomWest(), nullptr);

  EXPECT_EQ(h->findRoom("LobbyRestaurant")->getRoomNorth(), nullptr);
  EXPECT_EQ(h->findRoom("LobbyRestaurant")->getRoomEast(),
  h->findRoom("Lobby"));
  EXPECT_EQ(h->findRoom("LobbyRestaurant")->getRoomSouth(), nullptr);
  EXPECT_EQ(h->findRoom("LobbyRestaurant")->getRoomWest(), nullptr);

  EXPECT_EQ(h->findRoom("HotelRoom")->checkRoomInv(2), true);
  EXPECT_EQ(h->findRoom("HotelBathroom")->checkRoomInv(1), true);
  EXPECT_EQ(h->findRoom("HotelBalcony")->checkRoomInv(3), true);
  EXPECT_EQ(h->findRoom("Hallway")->checkRoomInv(4), true);
  EXPECT_EQ(h->findRoom("Hallway")->checkRoomInv(5), true);
  EXPECT_EQ(h->findRoom("HallwayElevator")->checkRoomInv(6), true);
  EXPECT_EQ(h->findRoom("LobbyRestaurant")->checkRoomInv(7), true);

  delete h;
}

TEST(testHotel, findRoomTest) {
  Hotel* h = new Hotel();
  EXPECT_NE(h->findRoom("HotelRoom"), nullptr);
  EXPECT_EQ(h->findRoom("Casino"), nullptr);
  delete h;
}

TEST(testHotel, getHotelTest) {
  Hotel* h = new Hotel();
  EXPECT_NO_THROW(h->getHotel());
  delete h;
}
