//
// Created by Catalin on 12/28/2025.
//

#ifndef OOP_SAVEMANAGER_H
#define OOP_SAVEMANAGER_H
#pragma once
#include "Player.h"

class SaveManager {
private:
  SaveManager() = default;

public:
  SaveManager(const SaveManager &) = delete;
  SaveManager &operator=(const SaveManager &) = delete;

  static SaveManager &getInstance();

  bool savePlayer(const Player &player);
  bool loadPlayer(Player &player);
  bool hasSave() const;
};

#endif // OOP_SAVEMANAGER_H