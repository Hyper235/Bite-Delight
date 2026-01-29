//
// Created by Catalin on 10/29/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Order.h"
#include <queue>
#include <string>
class Player {
protected:
  std::string name;
  float balance;
  std::queue<Order> orders;
  std::size_t currentStation = 0;
  unsigned int days;

public:
  Player();                                    // constructor implicit
  Player(const std::string &n, float balance); // parametric
  // getters
  const std::string &getName() const { return name; }
  float getBalance() const { return balance; }
  unsigned int getDays() const { return days; }
  // setter
  void setBalance(float b) { balance = b; }
  void setName(const std::string &n) { name = n; }
  void setDays(unsigned int d) { days = d; }
  // <<
  friend std::ostream &operator<<(std::ostream &os, const Player &p);
  // altele
  void finishOrder();
};
#endif // OOP_PLAYER_H