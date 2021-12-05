//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Implementation file for Player class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#include "../include/parse.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include "../include/Exceptions.h"
#include "../include/Player.h"
#include "../include/Flag.h"

std::vector<std::string> getInput() {
  std::vector<std::string> wordvec;
  std::string input = "";
  int i = 0;
  int j = 0;
  getline(std::cin, input);
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  while (i != input.size()) {
    while (i != input.size() && (input[i] == ' ')) {
      i++;
    }
    j = i;
    while (j != input.size() && (input[j] != ' ')) {
      j++;
    }
    if (i != j) {
      wordvec.push_back(input.substr(i, j-i));
      i = j;
    }
  }
  return wordvec;
}

void parse(Player* player, Flag* gamestate, Hotel* htl,
   std::vector<std::string> wordvec) {
  int size = wordvec.size();
  if (wordvec.at(0) == "help") {
    player->help();
  } else if (wordvec.at(0) == "move" && size >= 2) {
    if (wordvec.at(1) == "north") {
      player->roomMove('n');
    } else if (wordvec.at(1) == "west") {
      player->roomMove('w');
    } else if (wordvec.at(1) == "south") {
      player->roomMove('s');
    } else if (wordvec.at(1) == "east") {
      player->roomMove('e');
    } else {
      std::cout << std::endl << "The second word you entered was not"
      " recognized as a command" << std::endl;
    }
  } else if (wordvec.at(0) == "interact" && size >= 2) {
    if (wordvec.at(1) == "key") {
      if (player->checkInv(1) == true) {
        if ((player->getCurRoom()->getName() == "HotelRoom") &&
        (!gamestate->getUnlockDoor())) {
          std::cout << "You use the KEY on the DOOR and it unlocks."
          << std::endl;
          gamestate-> setUnlockDoor(true);
          player->getCurRoom()->setRoomNorth(htl->findRoom("Hallway"));
        } else if ((player->getCurRoom()->getName() == "HotelRoom") &&
        (gamestate->getUnlockDoor())) {
          std::cout << "The DOOR is already unlocked" << std::endl;
        } else {
          std::cout << "You can't find a keyhole to use the KEY." << std::endl;
        }
      } else if (player->getCurRoom()->checkRoomInv(1) == true) {
        std::cout << "You can't see anywhere to use the KEY.\n"
        "Did you mean to TAKE the KEY?" << std::endl;
      } else {
        std::cout << "You don't see a key" << std::endl;
      }
    } else if (wordvec.at(1) == "door") {
      if (player->checkInv(1) == true) {
        if ((player->getCurRoom()->getName() == "HotelRoom") &&
        (!gamestate->getUnlockDoor())) {
          std::cout << "You use the KEY on the DOOR and it unlocks."
          << std::endl;
          gamestate-> setUnlockDoor(true);
          player->getCurRoom()->setDescription("Looking around the HOTEL ROOM,"
           " you notice a dresser,\n"
            "a bed, a closet, and a lamp. There as a DOOR to the north,\n"
            "a BATHROOM to the west, and a BALCONY to the south.");
          player->getCurRoom()->setRoomNorth(htl->findRoom("Hallway"));
        } else if ((player->getCurRoom()->getName() == "HotelRoom") &&
        (gamestate->getUnlockDoor())) {
          std::cout << "The DOOR is already unlocked" << std::endl;
        } else  if (player->getCurRoom()->getName() == "Hallway") {
          switch (gamestate->getKnock()) {
            case 0:
              std::cout << "You knock on the DOOR and hear an"
                " angry grunt from the other side." << std::endl;
              gamestate->setKnock();
              break;
            case 1:
              std::cout << "You knock on the DOOR again getting no response."
              << std::endl;
              gamestate->setKnock();
              break;
            case 2:
              std::cout << "You knock on the DOOR this time hearing a KLACK."
              << std::endl;
              gamestate->setKnock();
              break;
            case 3:
              std::cout << "You knock one more time." << std::endl;
              player->setPlayerRoom(htl->findRoom("FailureKnocking"));
              std::cout << player->getCurRoom()->getDescription() << std::endl;
              break;
            }
          } else {
            std::cout << "You don't see any doors that interest you"
            << std::endl;
          }
        } else {
          std::cout << "The door is locked." << std::endl;
        }
      } else if (wordvec.at(1) == "railing") {
        if (player->getCurRoom()->getName() == "HotelBalcony") {
          std::cout << "You lean against the RAILING admiring\n"
          "the charming view you have at this height. Then the RAILING snaps."
          << std::endl;
          player->setPlayerRoom(htl->findRoom("FailureBalcony"));
          std::cout << player->getCurRoom()->getDescription() << std::endl;
        } else {
          std::cout << "You can't do that now." << std::endl;
        }
      } else if (wordvec.at(1) == "painting") {
        if ((player->getCurRoom()->getName() == "Hallway") &&
        (!gamestate->getFixedPicture())) {
          std::cout << "You fix the PAINTING." << std::endl;
          gamestate->setFixedPicture(true);
          player->getCurRoom()->setDescription("You made it out of the room"
          " and into the HALLWAY.\nIt is long, empty, and full of PAINTINGS."
           " You notice an entrance to a STAIRCASE to the west,\n"
           "an ELEVATOR with an Out-Of-Order sign to the east,"
           " and another DOOR to the north");
        } else if ((player->getCurRoom()->getName() == "Hallway") &&
        (gamestate->getFixedPicture())) {
          std::cout << "You tilt the PAINTING back to a crooked position.\n"
          "Why would you do that?" << std::endl;
          gamestate->setFixedPicture(false);
          htl->findRoom("HallwayStairwell")->setRoomWest(nullptr);
          player->getCurRoom()->setDescription("You made it out of the room"
          " and into the HALLWAY.\n"
            "It is long, empty, and full of PAINTINGS, one of which "
            "is angled differently.\nYou notice an entrance"
            " to a STAIRCASE to the west,\n"
            "an ELEVATOR with an Out-Of-Order sign to the east, "
            "and another DOOR to the north");
          htl->findRoom("HallwayStairwell")->setDescription("In the"
             " STAIRWELL, you see a CLEANER with a cleaning cart.\n"
              "You see a flight of stairs to the west that"
              " leads to the LOBBY,\n"
              "but it's blocked by the cart.");
        } else {
          std::cout << "You can't do that now." << std::endl;
        }
      } else if (wordvec.at(1) == "button") {
        if (player->getCurRoom()->getName() == "HallwayElevator") {
          player->setPlayerRoom(htl->findRoom("FailureElevator"));
          std::cout << player->getCurRoom()->getDescription() << std::endl;
        } else {
          std::cout << "You can't do that now." << std::endl;
        }
      } else if (wordvec.at(1) == "wallet") {
        if (!gamestate->getWallet()) {
          std::cout << "You don't have your WALLET with you." << std::endl;
        } else if ((gamestate->getWallet()) &&
        (player->getCurRoom()->getName() == "LobbyReception") &&
        (!gamestate->getPaidForRoom())) {
          std::cout << "You pay for your room and checkout successfully"
          << std::endl;
          gamestate->setPaidForRoom(true);
          htl->findRoom("Lobby")->setRoomSouth(htl->findRoom("Victory"));
        } else if ((gamestate->getWallet()) &&
        (player->getCurRoom()->getName() == "LobbyReception") &&
        (gamestate->getPaidForRoom())) {
          std::cout << "You have already checked out." << std::endl;
        } else {
          std::cout << "You can't do that now." <<std::endl;
        }
      } else if (wordvec.at(1) == "cleaner") {
        if ((player->getCurRoom()->getName() == "HallwayStairwell") &&
        (!gamestate->getFixedPicture())) {
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
        } else if ((player->getCurRoom()->getName() == "HallwayStairwell") &&
        (gamestate->getFixedPicture())) {
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
          player->getCurRoom()->setRoomWest(htl->findRoom("Lobby"));
          player->getCurRoom()->setDescription("In the STAIRWELL,"
          " you see a CLEANER with a cleaning cart.\n"
            "You see a flight of stairs to the west that leads to the LOBBY.");
        }
      } else if (wordvec.at(1) == "receptionist") {
        if ((player->getCurRoom()->getName() == "LobbyReception") &&
        (!gamestate->getPaidForRoom()) &&
        (gamestate->getWallet())) {
          std::cout << "You pay for your room and checkout successfully"
          << std::endl;
          gamestate->setPaidForRoom(true);
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
          htl->findRoom("Lobby")->setRoomSouth(htl->findRoom("Victory"));
        } else if ((player->getCurRoom()->getName() == "LobbyReception") &&
        (!gamestate->getPaidForRoom()) &&
        (!gamestate->getWallet())) {
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
          std::cout << "You don't have your WALLET with you." <<std::endl;
        } else if (player->getCurRoom()->getName() == "LobbyReception") {
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
        } else {
          std::cout << "You can't do that now" <<std::endl;
        }
      } else if (wordvec.at(1) == "chef") {
        if ((player->getCurRoom()->getName() == "LobbyRestaurant") &&
        (player->checkInv(7) == false)) {
          gamestate->setWallet(false);
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
          player->addPlayerInv(7);
          gamestate->setWallet(true);
        } else if ((player->getCurRoom()->getName() == "LobbyRestaurant") &&
        (player->checkInv(7) == true)) {
          player->getCurRoom()->getCharacter()->setDialogue(gamestate);
          std::cout << player->getCurRoom()->getCharacter()->getDialogue()
          << std::endl;
        } else {
          std::cout << "You can't do that now" <<std::endl;
        }
      } else {
        std::cout << std::endl << "The second word you entered was not"
        " recognized as a command" << std::endl;
      }
    } else if (wordvec.at(0) == "take") {
      if (wordvec.at(1) == "key") {
        if (player->checkInv(1) == false) {
          if (player->getCurRoom()->getName() == "HotelBathroom") {
            std::cout << "You pick up the KEY." << std::endl;
            player->take(1);
            player->getCurRoom()->setDescription("Entering the BATHROOM,\n"
            "you see a shower, a toilet, and a sink.");
          } else {
            std::cout << "There is no key to take." << std::endl;
          }
        } else {
          std::cout << "You already have the key" << std::endl;
        }
      } else if (wordvec.at(1) == "door") {
        if ((player->getCurRoom()->getName() == "HotelRoom") ||
        (player->getCurRoom()->getName() == "Hallway")) {
          std::cout << "You try to take the door but you are far too weak.\n"
          << std::endl;
        } else {
          std::cout << "You cannot do that now." << std::endl;
        }
      } else if (wordvec.at(1) == "railing") {
        if (player->getCurRoom()->getName() == "HotelBalcony") {
          std::cout << "You can't take the railing\n"
          "What what would you even do if you had it?" << std::endl;
        } else {
          std::cout << "You cannot do that now." << std::endl;
        }
      } else if (wordvec.at(1) == "painting") {
        if (player->getCurRoom()->getName() == "Hallway") {
          std::cout << "You go to take the PAINTING,\n"
          "but then you realize that is theft\n"
          "and you are not above the law." << std::endl;
        } else {
          std::cout << "You cannot do that now." << std::endl;
        }
      } else {
        std::cout << "You cannot do that now." << std::endl;
      }
    } else if (wordvec.at(0) == "inventory") {
      player->inv();
      std::cout << std::endl;
    } else {
      std::cout << "The first word you entered was not recognized"
      " as a command or you need to add a second word example \"move north\"\n"
      "To see list of possible commands please enter HELP";
      std::cout << std::endl;
  }
  return;
}
