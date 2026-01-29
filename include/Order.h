#ifndef OOP_ORDER_H
#define OOP_ORDER_H
#include "FoodItem.h"
#include "Observer.h"
#include "PricingStrategy.h"
#include <chrono>
#include <memory>
#include <vector>

enum class Dif { EASY, MEDIUM, HARD };
class Order : public Subject {
private:
  static unsigned int nextId;
  unsigned int id;
  float tips;
  Dif difficulty;
  std::unique_ptr<PricingStrategy> m_pricingStrategy;
  std::vector<FoodItem> items;
  std::vector<bool> prepared;
  std::chrono::system_clock::time_point timestamp =
      std::chrono::system_clock::now();
  std::chrono::seconds maxDuration;
  static unsigned int finishedOrders;
  bool notified = false;

  void setStrategy(Dif diff);

public:
  Order();
  Order(unsigned int i, float tipsAmount, Dif diff, unsigned int maxSec,
        const std::vector<FoodItem> &itemsList = {});
  Order(const Order &other);
  Order &operator=(const Order &other);

  void setTips(unsigned int t) { tips = t; }
  void setDifficulty(Dif d) { difficulty = d; }
  void setMaxDuration(unsigned int seconds) {
    maxDuration = std::chrono::seconds(seconds);
  }
  [[nodiscard]] unsigned int getID() const { return id; }
  std::chrono::system_clock::time_point getTimestamp() const {
    return timestamp;
  }
  std::chrono::seconds getMaxDuration() const { return maxDuration; }
  void addItemToOrder(const FoodItem &it);
  friend std::ostream &operator<<(std::ostream &os, const Order &o);
  [[nodiscard]] bool hasExpired() const;
  [[nodiscard]] float calc() const;
  bool registerPreparedItem(const FoodItem &preparedItem);
      bool isComplete() const;
      void checkAndNotify();
      void forceComplete();
      void forceExpire();
};

#endif