//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Header file for Flag class
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef FLAG_H
#define FLAG_H


/// \brief \class Flag Class has all
/// the game flags that are needed in the which need.
/// Game Flags are used to make
/// important changes and actions within the game.

class Flag {
 public:
  /// \brief Getter and setter for the game flag fixedPicture.
  /// Within the game to move forword
  /// the bool fixedPicture must be set to true.
  /// param[bool] for fixedPicture sets fixedPicture to true
  bool getFixedPicture();
  void setFixedPicture(bool);

  /// \brief Getter and setter for the game flag paidForRoom.
  /// The player must pay for his room to get out of the hotel.
  /// param[bool] for paidForRoom sets paidForRoom to true

  bool getPaidForRoom();
  void setPaidForRoom(bool);

  /// \brief sets paidForRoom to trueGetter and setter
  /// for the game flag wallet.
  /// The player must get the wallet in order to pay for the room.
  /// param[bool] for Wallet sets have Wallet to true
  bool getWallet();
  void setWallet(bool);

  /// \brief getter and setter for the game flag getUnlockDoor
  /// The player must unlock the door in order to move on
  /// with escaping the hotel.
  /// param[bool] for unlockDoor  sets for unlockDoor
  bool getUnlockDoor();
  void setUnlockDoor(bool);

  /// \brief Getter and Setter for the game flag knock.
  /// *Knocks is used for the game to be more interesting. And play around.
  /// param[bool] bool for Knocks increases doorKnock by 1
  int getKnock();
  void setKnock();

 private:
  /// \brief All the private variables that are needed for flag class.
  /// param[bool] fixedPicture set true if the picture is set by the picture.
  /// param[bool] paidForRoom used to set true if the
  /// player has paid for the room.
  /// param[bool] haveWallet set true if the player has
  /// the wallet in the inventory.
  /// param[bool] unlockDoor used to set true if the door is unlocked.
  /// param[bool] doorKnock used to count the number of knocks on the door.
  bool fixedPicture = false;
  bool paidForRoom = false;
  bool haveWallet = false;
  bool unlockDoor = false;
  int doorKnock = 0;
};

#endif
