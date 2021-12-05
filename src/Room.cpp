//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Room class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/Room.h"
#include <string>
#include "../include/Inventory.h"

void Room::setRoomNorth(Room* place) {
  roomNorth = place;
}

Room* Room::getRoomNorth() {
  return roomNorth;
}

void Room::setRoomEast(Room* place) {
  roomEast = place;
}

Room* Room::getRoomEast() {
  return roomEast;
}

void Room::setRoomSouth(Room* place) {
  roomSouth = place;
}

Room* Room::getRoomSouth() {
  return roomSouth;
}

void Room::setRoomWest(Room* place) {
  roomWest = place;
}

Room* Room::getRoomWest() {
  return roomWest;
}

void Room::setName(std::string n) {
  name = n;
}

std::string Room::getName() {
  return name;
}

Inventory Room::getRoomInv() {
  return inventory;
}

bool Room::addRoomInv(int item) {
  if (inventory.addInv(item)) {
    return true;
  } else {
    return false;
  }
}

bool Room::removeRoomInv(int item) {
  if (inventory.remove(item)) {
    return true;
  } else {
    return false;
  }
}

bool Room::checkRoomInv(int item) {
  if (inventory.checkInv(item)) {
    return true;
  } else {
    return false;
  }
}

std::string Room::getDescription() {
  return description;
}

void Room::setCharacter(NPC* person) {
  character = person;
}

NPC* Room::getCharacter() {
  return character;
}

void Room::setDescription(string newDesc) {
  description = newDesc;
}
HotelRoom::HotelRoom() {
  description = "Looking around the HOTEL ROOM, you notice a dresser,\n"
    "a bed, a closet, and a lamp. There as a locked DOOR to the north,\n"
    "a BATHROOM to the west,and a BALCONY to the south.";
  name = "HotelRoom";
}

HotelBathroom::HotelBathroom() {
  description = "Entering the BATHROOM, you see a shower, a toilet,\n"
    "and a sink. You notice a KEY next to the sink.";
  name = "HotelBathroom";
}

HotelBalcony::HotelBalcony() {
  description = "Out on the BALCONY, you can see that you are several\n"
    "stories up. You notice a set of chairs, a table and the balcony RAILING.";
  name = "HotelBalcony";
}

Hallway::Hallway() {
  description = "You made it out of the room and into the HALLWAY.\n"
    "It is long, empty, and full of PAINTINGS, one of which "
    "is angled differently.\n"
    "You notice an entrance to a STAIRCASE to the west,\n"
    "an ELEVATOR with an Out-Of-Order sign to the east,\n"
    "and another DOOR to the north.";
  name = "Hallway";
}

HallwayStairwell::HallwayStairwell() {
  description = "In the STAIRWELL, you see a CLEANER with a cleaning cart.\n"
    "You see a flight of stairs to the west that leads to the LOBBY,\n"
    "but it's blocked by the cart.";
  name = "HallwayStairwell";
}

HallwayElevator::HallwayElevator() {
  description = "You pry the elevator doors open and step inside.\n"
    "You see one large BUTTON labelled \"Lobby\".";
  name = "HallwayElevator";
}

Lobby::Lobby() {
  description = "Entering the main LOBBY area, you see a large desk\n"
    "labelled RECEPTION to the north, a lobby RESTAURANT to the west,\n"
    "and the main EXIT to the south.";
  name = "Lobby";
}

LobbyReception::LobbyReception() {
  description = "Going to RECEPTION, you see the RECEPIONIST\n"
  "waiting behind the desk.";
  name = "LobbyReception";
}

LobbyRestaurant::LobbyRestaurant() {
  description = "Upon entering the RESTAURANT,\n"
   "you notice many empty tables and the restaurant CHEF.";
  name = "LobbyRestaurant";
}

Failure1::Failure1() {
  description = "You hurl over the edge and plummet to your death.\n"
    "What did you think would happen?\n"
    "You Lose.";
  name = "FailureBalcony";
}

Failure2::Failure2() {
  description = "The door opens suddenly and an angry old man comes out\n"
    "holding a shotgun. He shoots you dead.\n"
    "You shouldn't have kept knocking.\n"
    "You Lose.";
  name = "FailureKnocking";
}

Failure3::Failure3() {
  description = "You walk out of the hotel and immediately get arrested.\n"
    "You have to checkout at reception before you leave.\n"
    "You Lose.";
  name = "FailureArrested";
}

Failure4::Failure4() {
  description = "Pressing the button, you hear calming elevator music\n"
    "as the elevator cable snaps and you plummet.\n"
    "You should've listened to the sign.\n"
    "You Lose.";
  name = "FailureElevator";
}

Victory::Victory() {
  description = "Congratulations, you have escaped the hotel...\n"
    "or maybe you just checked out.";
  name = "Victory";
}
