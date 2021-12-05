//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Main file for Escape The Hotel
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include <iostream>
#include <string>
#include <vector>
#include "../include/Exceptions.h"
#include "../include/Flag.h"
#include "../include/Inventory.h"
#include "../include/NPC.h"
#include "../include/parse.h"
#include "../include/Player.h"
#include "../include/Room.h"
#include "../include/Hotel.h"

// Item index:
//  1 - Key: HotelBathroom (Take/Use)
//  2 - Door: HotelRoom (Interact/Move)
//  3 - Railing: HotelBalcony (Interact/Move)
//  4 - Painting: Hallway (Interact)
//  5 - Door: Hallway (Interact)
//  6 - Button: HallwayElevator (Interact)
//  7 - Wallet: LobbyRestaurant (Interact/Use)
//

int main() {
  Hotel* h = new Hotel();
  Player* p = new Player();
  Flag* f = new Flag();
  Cleaner* cl = new Cleaner();
  Receptionist* rc = new Receptionist();
  Chef* ch = new Chef();

  // Gamestart Message
  std::cout << "You awaken suddenly in an unfamiliar bedroom.\n";
  std::cout << "Judging by the lack of character and smell of cheap soap,\n";
  std::cout << "you determine that this is a hotel room.\n";
  std::cout << "You don't what happened, and you don't know how you got here,";
  std::cout << "\nbut you do know one thing... YOU MUST ESCAPE\n";
  std::cout << "Welcome to ESCAPE THE HOTEL\n\n";

  // Initializing Player and NPC's
  p->setPlayerRoom(h->findRoom("HotelRoom"));
  h->findRoom("HallwayStairwell")->setCharacter(cl);
  h->findRoom("LobbyReception")->setCharacter(rc);
  h->findRoom("LobbyRestaurant")->setCharacter(ch);
  std::cout << p->getCurRoom()->getDescription() << std::endl;

  // Game Loop
    std::vector<std::string> input;
  do {
    input = getInput();
    if (!input.empty()) {parse(p, f, h, input);}
  } while (!(p->getCurRoom() == h->findRoom("FailureBalcony")) &&
  !(p->getCurRoom() == h->findRoom("FailureKnocking")) &&
  !(p->getCurRoom() == h->findRoom("FailureArrested")) &&
  !(p->getCurRoom() == h->findRoom("FailureElevator")) &&
  !(p->getCurRoom() == h->findRoom("Victory")));

  delete h;
  delete p;
  delete f;
  delete cl;
  delete rc;
  delete ch;
  return 0;
}
