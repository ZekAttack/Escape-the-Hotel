//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Hotel class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/Hotel.h"
#include <vector>
#include <string>
#include "../include/Room.h"
#include "../include/NPC.h"
#include "../include/Exceptions.h"

Hotel::Hotel() {
  HotelRoom* hr = new HotelRoom();
  HotelBathroom* hbt = new HotelBathroom();
  HotelBalcony* hbl = new HotelBalcony();
  Hallway* hl = new Hallway();
  HallwayStairwell* hs = new HallwayStairwell();
  HallwayElevator* he = new HallwayElevator();
  Lobby* lb = new Lobby();
  LobbyReception* lrc = new LobbyReception();
  LobbyRestaurant* lrs = new LobbyRestaurant();
  Failure1* f1 = new Failure1();
  Failure2* f2 = new Failure2();
  Failure3* f3 = new Failure3();
  Failure4* f4 = new Failure4();
  Victory* v = new Victory();

  hotelRooms.push_back(hr);
  hotelRooms.push_back(hbt);
  hotelRooms.push_back(hbl);
  hotelRooms.push_back(hl);
  hotelRooms.push_back(hs);
  hotelRooms.push_back(he);
  hotelRooms.push_back(lb);
  hotelRooms.push_back(lrc);
  hotelRooms.push_back(lrs);
  hotelRooms.push_back(f1);
  hotelRooms.push_back(f2);
  hotelRooms.push_back(f3);
  hotelRooms.push_back(f4);
  hotelRooms.push_back(v);

  hr->setRoomNorth(nullptr);
  hr->setRoomEast(nullptr);
  hr->setRoomSouth(hbl);
  hr->setRoomWest(hbt);

  hbt->setRoomNorth(nullptr);
  hbt->setRoomEast(hr);
  hbt->setRoomSouth(nullptr);
  hbt->setRoomWest(nullptr);

  hbl->setRoomNorth(hr);
  hbl->setRoomEast(nullptr);
  hbl->setRoomSouth(f1);
  hbl->setRoomWest(nullptr);

  hl->setRoomNorth(nullptr);
  hl->setRoomEast(he);
  hl->setRoomSouth(hr);
  hl->setRoomWest(hs);

  hs->setRoomNorth(nullptr);
  hs->setRoomEast(hl);
  hs->setRoomSouth(nullptr);
  hs->setRoomWest(nullptr);

  he->setRoomNorth(nullptr);
  he->setRoomEast(nullptr);
  he->setRoomSouth(nullptr);
  he->setRoomWest(hl);

  lb->setRoomNorth(lrc);
  lb->setRoomEast(hs);
  lb->setRoomSouth(f3);
  lb->setRoomWest(lrs);

  lrc->setRoomNorth(nullptr);
  lrc->setRoomEast(nullptr);
  lrc->setRoomSouth(lb);
  lrc->setRoomWest(nullptr);

  lrs->setRoomNorth(nullptr);
  lrs->setRoomEast(lb);
  lrs->setRoomSouth(nullptr);
  lrs->setRoomWest(nullptr);

  hr->addRoomInv(2);
  hbt->addRoomInv(1);
  hbl->addRoomInv(3);
  hl->addRoomInv(4);
  hl->addRoomInv(5);
  he->addRoomInv(6);
  lrs->addRoomInv(7);
}

Hotel::~Hotel() {
  for (auto& it : hotelRooms) {
    delete it;
  }
}

Room* Hotel::findRoom(std::string place) {
  for (int i = 0; i < hotelRooms.size(); i++) {
    if (hotelRooms.at(i)->getName() == place) {
      return hotelRooms.at(i);
    } else {
      continue;
    }
    throw invalid_parameter("Invalid room name");
  }
  return nullptr;
}

std::vector<Room*> Hotel::getHotel() {
  return hotelRooms;
}
