//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for Room class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef ROOM_H
#define ROOM_H
#include "Inventory.h"
#include "NPC.h"
#include <string>

/// \brief \class
/// \brief
class Room {
 public:
  /// \brief destructor
  virtual ~Room() {}

  /// \brief get the description for the room so that the program will know
  /// which room it is.
  std::string getDescription();

  /// \brief Sets the room to the North of the current room
  /// Returns true if placement was succesful, returns false otherwise
  /// \param[Room*] for north room
  void setRoomNorth(Room* place);

  /// \brief Return the room North of the current one
  Room* getRoomNorth();

  /// \brief Sets the room to the East of the current room
  /// Returns true if placement was succesful, returns false otherwise
  /// \param[Room*]  for east room
  void setRoomEast(Room* place);

  /// \brief Return the room North of the current one
  Room* getRoomEast();

  /// \brief Sets the room to the South of the current room
  /// Returns true if placement was succesful, returns false otherwise
  /// \param[Room*] for south room
  void setRoomSouth(Room* place);

  /// \brief Return the room North of the current one
  Room* getRoomSouth();

  /// \brief Sets the room to the West of the current room
  /// Returns true if placement was succesful, returns false otherwise
  /// \param[Room*] for west room
  void setRoomWest(Room* place);

  /// \brief Return the room North of the current one
  Room* getRoomWest();

  /// \brief Sets the name of the room
  /// \param[string n]
  void setName(std::string n);

  /// \brief Returns the name of the room
  std::string getName();

  /// \brief Returns the inventory
  Inventory getRoomInv();

  /// \brief Adds items to the room inventory
  /// Returns true if addition was succesful, returns false otherwise
  /// \param[int] add an item
  bool addRoomInv(int item);

  /// \brief  Removes items from the room Inventory
  /// Returns true if removal was succesful, returns false otherwise
  /// \param[item] removes item in inventory
  bool removeRoomInv(int item);

  /// \brief Checks if a given item is in the inventory
  /// Returns true if found, returns false otherwise
  /// \param[item] checks for the items in the room
  bool checkRoomInv(int item);

  /// \brief Sets the character in the room
  /// \param[NPC*] pointer to NPC person
  void setCharacter(NPC* person);

  /// \brief Returns a pointer to the NPC in the room
  NPC* getCharacter();

  /// \brief Sets the description of the room
  /// \param[newDesc] changes description
  void setDescription(string newDesc);


 private:
  Inventory inventory;
  NPC* character;
  Room *roomNorth = nullptr;
  Room *roomEast = nullptr;
  Room *roomSouth = nullptr;
  Room *roomWest = nullptr;

 protected:
  std::string name;
  std::string description;
};

/// \brief \class constructor and destructor for HotelRoom
class HotelRoom : public Room {
 public:
  HotelRoom();
  ~HotelRoom() {}
};

/// \brief \class constructor and destructor for HotelBathroom
class HotelBathroom : public Room {
 public:
  HotelBathroom();
  ~HotelBathroom() {}
};

/// \brief \class constructor and destructor for HotelBalcony
class HotelBalcony : public Room {
 public:
  HotelBalcony();
  ~HotelBalcony() {}
};

/// \brief \class constructor and destructor for Hallway
class Hallway : public Room {
 public:
  Hallway();
  ~Hallway() {}
};

/// \brief \class constructor and destructor for HallwayStairwell
class HallwayStairwell : public Room {
 public:
  HallwayStairwell();
  ~HallwayStairwell() {}
};

/// \brief \class constructor and destructor HallwayElevator
class HallwayElevator : public Room {
 public:
  HallwayElevator();
  ~HallwayElevator() {}
};

/// \brief \class constructor and destructor Lobby
class Lobby : public Room {
 public:
  Lobby();
  ~Lobby() {}
};

/// \brief \class constructor and destructor LobbyReception
class LobbyReception : public Room {
 public:
  LobbyReception();
  ~LobbyReception() {}
};

/// \brief \class constructor and destructor LobbyRestaurant
class LobbyRestaurant : public Room {
 public:
  LobbyRestaurant();
  ~LobbyRestaurant() {}
};

/// \brief all the failure rooms within the game
/// \brief \class constructor and destructor Failure1
class Failure1 : public Room {
 public:
  Failure1();
  ~Failure1() {}
};

/// \brief \class constructor and destructor Failure2
class Failure2 : public Room {
 public:
  Failure2();
  ~Failure2() {}
};

/// \brief \class constructor and destructor Failure3
class Failure3 : public Room {
 public:
  Failure3();
  ~Failure3() {}
};

/// \brief \class constructor and destructor Failure4
class Failure4 : public Room {
 public:
  Failure4();
  ~Failure4() {}
};

/// \brief \class constructor and destructor Victory
class Victory : public Room {
 public:
  Victory();
  ~Victory() {}
};

#endif
