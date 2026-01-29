#include "../include/Order.h"
#include "../include/FoodItem.h"

unsigned int Order::nextId = 1;

void Order::setStrategy(Dif diff) {
  switch (diff) {
  case Dif::EASY:
    m_pricingStrategy = std::make_unique<EasyPricingStrategy>();
    break;
  case Dif::MEDIUM:
    m_pricingStrategy = std::make_unique<MediumPricingStrategy>();
    break;
  case Dif::HARD:
    m_pricingStrategy = std::make_unique<HardPricingStrategy>();
    break;
  }
}

Order::Order()
    : id(nextId++), tips(0.0f), difficulty(Dif::EASY),
      timestamp(std::chrono::system_clock::now()),
      maxDuration(static_cast<std::chrono::seconds::rep>(0)), notified(false) {
  setStrategy(difficulty);
  prepared.assign(items.size(), false);
}

Order::Order(unsigned int i, float tipsAmount, Dif diff, unsigned int maxSec,
             const std::vector<FoodItem> &itemsList)
    : id(i), tips(tipsAmount), difficulty(diff), items(itemsList),
      timestamp(std::chrono::system_clock::now()),
      maxDuration(static_cast<std::chrono::seconds::rep>(maxSec)),
      notified(false) {
  setStrategy(difficulty);
  prepared.assign(items.size(), false);
}

Order::Order(const Order &other)
    : Subject(other), id(other.id), tips(other.tips),
      difficulty(other.difficulty), items(other.items), prepared(other.prepared),
      timestamp(other.timestamp), maxDuration(other.maxDuration),
      notified(other.notified) {
  setStrategy(other.difficulty);
}

Order &Order::operator=(const Order &other) {
  if (this == &other) {
    return *this;
  }
  Subject::operator=(other);
  id = other.id;
  tips = other.tips;
  difficulty = other.difficulty;
  items = other.items;
  prepared = other.prepared;
  timestamp = other.timestamp;
  maxDuration = other.maxDuration;
  notified = other.notified;
  setStrategy(other.difficulty);
  return *this;
}

void Order::addItemToOrder(const FoodItem &it) {
  items.push_back(it);
  prepared.push_back(false);
}

std::ostream &operator<<(std::ostream &os, const Order &o) {
  std::time_t t = std::chrono::system_clock::to_time_t(o.timestamp);
  std::tm tm = *std::localtime(&t);

  char buffer[9];
  std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &tm);

  if (o.difficulty == Dif::EASY)
    os << "EASY\n";
  else if (o.difficulty == Dif::MEDIUM)
    os << "MEDIUM\n";
  else
    os << "HARD\n";

  os << "Order [" << o.id << " | (Timestamp: " << buffer
     << " Max Time: " << o.maxDuration.count() << "s)] " << o.calc()
     << " RON\n";

  os << "Contents:\n";
  for (const FoodItem &it : o.items)
    os << it << "\n";

  return os;
}

bool Order::hasExpired() const {
  auto now = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::seconds>(now - this->timestamp);
  return elapsed > this->maxDuration;
}

float Order::calc() const {
  float basePrice = 0.0f;
  for (const FoodItem &it : items) {
    basePrice += it.getPrice();
  }
  return m_pricingStrategy->calculate(basePrice);
}

bool Order::registerPreparedItem(const FoodItem &preparedItem) {
  bool itemRegistered = false;
  for (std::size_t i = 0; i < this->items.size(); ++i) {
    if (!this->prepared[i] && this->items[i].GetID() == preparedItem.GetID()) {
      this->prepared[i] = true;
      itemRegistered = true;
      break;
    }
  }
  if (itemRegistered) {
    checkAndNotify();
  }
  return itemRegistered;
}

bool Order::isComplete() const {
  if (items.empty() || prepared.size() != items.size()) {
    return false;
  }
  for (bool p : prepared) {
    if (!p)
      return false;
  }
  return true;
}

void Order::checkAndNotify() {
  if (notified) {
    return;
  }
  if (isComplete() || hasExpired()) {
    notifyObservers(this);
    notified = true;
  }
}

void Order::forceComplete() {
  for (size_t i = 0; i < prepared.size(); ++i) {
    prepared[i] = true;
  }
  checkAndNotify();
}

void Order::forceExpire() {
  timestamp = std::chrono::system_clock::now() - std::chrono::hours(1);
  checkAndNotify();
}
