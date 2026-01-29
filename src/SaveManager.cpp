#include "SaveManager.h"
#include <filesystem>
#include <fstream>

#define SAVE_PATH "saves/player.txt"

SaveManager &SaveManager::getInstance() {
  static SaveManager instance;
  return instance;
}

bool SaveManager::hasSave() const { return std::filesystem::exists(SAVE_PATH); }

bool SaveManager::savePlayer(const Player &player) {
  std::filesystem::create_directories("saves");

  std::ofstream out(SAVE_PATH);
  if (!out)
    return false;

  out << player.getName() << "\n";
  out << player.getBalance() << "\n";
  out << player.getDays() << "\n";

  return true;
}

bool SaveManager::loadPlayer(Player &player) {
  std::ifstream in(SAVE_PATH);
  if (!in)
    return false;

  std::string name;
  float balance;
  unsigned int days;

  std::getline(in, name);
  in >> balance >> days;

  player.setName(name);
  player.setBalance(balance);
  player.setDays(days);

  return true;
}
