//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for Hotel class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include <vector>
#include <string>


/// \brief \class Hotel class will have all the rooms with it.
/// Rooms are used for the player to move around in and ecaspe the hotel.
class Hotel {
 public:
  /// \brief constructor
  Hotel();
  /// \brief destructor
  ~Hotel();

  /// \brief getHotel will all the rooms with in the hotel
  /// Returns a list of all the rooms within the hotel
  /// param[vector] vector for all the rooms
  std::vector<Room*> getHotel();

  /// \brief findRoom is used so that you can find which hotel room you need
  /// Returns what hotel room that you want
  /// param[string] string is used for each room
  Room* findRoom(std::string);

 private:
  std::vector<Room*> hotelRooms;
};

#endif
